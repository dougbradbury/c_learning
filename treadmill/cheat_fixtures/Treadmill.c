#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Fixtures.h"
#include "SlimList.h"
#include "treadmill/Api.h"
#include "format.h"

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
  double speed = SlimList_GetDoubleAt(args, 0);
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
  double speed = Api_GetTargetSpeed(self->api);
	ftoa(self->result, speed, 1);
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
  double speed = SlimList_GetDoubleAt(args, 0);  
  Api_SetMaximumSpeed(self->api, speed);
  return "";
}

SLIM_CREATE_FIXTURE(Treadmill)
	SLIM_FUNCTION(givenTreadmillSpeed)
	SLIM_FUNCTION(incrementSpeed)
	SLIM_FUNCTION(decrementSpeed)
	SLIM_FUNCTION(targetSpeed)
  SLIM_FUNCTION(givenMaxSpeed)
SLIM_END

