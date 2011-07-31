#include "Api.h"
#include <stdlib.h>
#include <memory.h>

typedef struct ApiStruct
{
    double targetSpeed;
    double maxSpeed;
} ApiStruct;

Api Api_Create(void)
{
     Api self = calloc(1, sizeof(ApiStruct));
     self->maxSpeed = 10.0;
     return self;
}

void Api_Destroy(Api self)
{
    free(self);
}

double Api_GetTargetSpeed(Api self)
{
  return self->targetSpeed;
}

void Api_SetTargetSpeed(Api self, double speed)
{
  self->targetSpeed = speed;
}

void Api_IncrementTargetSpeed(Api self)
{
  if(self->targetSpeed < self->maxSpeed) 
  {
    self->targetSpeed += 0.1;
  }
}

void Api_DecrementTargetSpeed(Api self)
{
  self->targetSpeed -= 0.1;
}

void Api_SetMaximumSpeed(Api self, double speed)
{
  self->maxSpeed = speed;
}
