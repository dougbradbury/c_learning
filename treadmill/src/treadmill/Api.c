#include "Api.h"
#include <stdlib.h>
#include "Uptime.h"
#include "hardware/Pwm.h"

typedef struct ApiStruct
{
  double targetSpeed;
  double maxSpeed;
  double distanceTraveled;
  long lastTimeChange;
} ApiStruct;

Api Api_Create(void)
{
  Api self = calloc(1, sizeof(ApiStruct));
  self->maxSpeed = 10.0;
  Uptime_Create();
  Pwm_Create();
  Pwm_SetPeriod(50000);
  return self;
}

void Api_Destroy(Api self)
{
  Pwm_Destroy();
  Uptime_Destroy();
  free(self);
}

double Api_GetTargetSpeed(Api self)
{
  return self->targetSpeed;
}

static double distance(double speed, long time_ms)
{
  return speed * time_ms / 3600000;
}

static double distanceSinceLastSpeedChange(Api self)
{
  int uptime = Uptime_MilliSeconds();
  return distance(self->targetSpeed, uptime - self->lastTimeChange);
}

double dutyCycleFromSpeed(double mph)
{
   return 0.067 * mph + 0.175;
}

void Api_SetTargetSpeed(Api self, double speed)
{
  self->distanceTraveled += distanceSinceLastSpeedChange(self);
  self->lastTimeChange = Uptime_MilliSeconds();
  self->targetSpeed = speed;
  Pwm_SetDutyCycle(dutyCycleFromSpeed(speed));
  Pwm_Start();
}

void Api_IncrementTargetSpeed(Api self)
{
  if(self->targetSpeed < self->maxSpeed)
  {
    Api_SetTargetSpeed(self, self->targetSpeed + 0.1);
  }
}

void Api_DecrementTargetSpeed(Api self)
{
  Api_SetTargetSpeed(self, self->targetSpeed - 0.1);
}

void Api_SetMaximumSpeed(Api self, double speed)
{
  self->maxSpeed = speed;
}

double Api_DistanceTravelled(Api self)
{
  return self->distanceTraveled + distanceSinceLastSpeedChange(self);
}

void Api_Reset(Api self)
{
  self->distanceTraveled = 0;
  self->lastTimeChange = Uptime_MilliSeconds();
}
