#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "Fixtures.h"
#include "SlimList.h"
#include "treadmill/api.h"

typedef struct Treadmill
{
	char result[32];
  Api api;
} Treadmill;

void* Treadmill_Create(StatementExecutor* errorHandler, SlimList* args)
{
	Treadmill* self = (Treadmill*)malloc(sizeof(Treadmill));
	memset(self, 0, sizeof(Treadmill));
  self->api = Api_Create();
	return self;
}

void Treadmill_Destroy(void* void_self)
{
	Treadmill* self = (Treadmill*)void_self;
  Api_Destroy(self->api);
	free(self);
}

static char* givenTreadmillSpeed(void* void_self, SlimList* args)
{
	Treadmill* self = (Treadmill*)void_self;
  char* speed_s = SlimList_GetStringAt(args, 0);
  double speed = atof(speed_s);
  Api_SetTargetSpeed(self->api, speed);
	return "";
}

static char* incrementSpeed(void* void_self, SlimList* args)
{
	Treadmill* self = (Treadmill*)void_self;
  Api_IncrementTargetSpeed(self->api);
	return "";
}

static char* targetSpeed(void* void_self, SlimList* args)
{
	Treadmill* self = (Treadmill*)void_self;
	snprintf(self->result, 32, "%.1f", Api_GetTargetSpeed(self->api));
	return self->result;
}

static char* decrementSpeed(void* void_self, SlimList* args)
{
	Treadmill* self = (Treadmill*)void_self;
  Api_DecrementTargetSpeed(self->api);
  return "";
}

static char* givenMaxSpeed(void* void_self, SlimList* args)
{
	Treadmill* self = (Treadmill*)void_self;
  char* speed_s = SlimList_GetStringAt(args, 0);
  double speed = atof(speed_s);
  Api_SetMaximumSpeed(self->api, speed);
}

SLIM_CREATE_FIXTURE(Treadmill)
	SLIM_FUNCTION(givenTreadmillSpeed)
	SLIM_FUNCTION(incrementSpeed)
	SLIM_FUNCTION(decrementSpeed)
	SLIM_FUNCTION(targetSpeed)
  SLIM_FUNCTION(givenMaxSpeed)
SLIM_END

