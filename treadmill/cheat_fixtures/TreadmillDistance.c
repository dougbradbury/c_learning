#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Fixtures.h"
#include "SlimList.h"
#include "treadmill/Api.h"
#include "FakeUptime.h"
#include "format.h"

typedef struct TreadmillDistance
{
	char result[32];
  Api api;
} TreadmillDistance;

void* TreadmillDistance_Create(StatementExecutor* errorHandler, SlimList* args)
{
	TreadmillDistance* self = (TreadmillDistance*)malloc(sizeof(TreadmillDistance));
	memset(self, 0, sizeof(TreadmillDistance));
  self->api = Api_Create();
	return self;
}

void TreadmillDistance_Destroy(void* void_self)
{
	TreadmillDistance* self = (TreadmillDistance*)void_self;
  Api_Destroy(self->api);
	free(self);
}

static char* reset(void* void_self, SlimList *args) {
	TreadmillDistance* self = (TreadmillDistance*)void_self;
  Api_Reset(self->api);
  return "";
}

static char* setSpeed(void* void_self, SlimList *args) {
	TreadmillDistance* self = (TreadmillDistance*)void_self;
  double speed = SlimList_GetDoubleAt(args, 0);
  Api_SetTargetSpeed(self->api, speed);
  return "";
}

static char* setTime(void* void_self, SlimList *args) {
	TreadmillDistance* self = (TreadmillDistance*)void_self;
  double minutes = SlimList_GetDoubleAt(args, 0);
  uptimeMillis += minutes*60*1000;
  return "";
}

static char* distance(void* void_self, SlimList *args) {
	TreadmillDistance* self = (TreadmillDistance*)void_self;
  double d = Api_DistanceTravelled(self->api);
	ftoa(self->result, d, 1);
	return self->result;
}
SLIM_CREATE_FIXTURE(TreadmillDistance)
	SLIM_FUNCTION(setSpeed)
	SLIM_FUNCTION(setTime)
	SLIM_FUNCTION(distance)
  SLIM_FUNCTION(reset)
SLIM_END
