#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Fixtures.h"
#include "SlimList.h"
#include "treadmill/Api.h"
#include "FakeUptime.h"
#include "format.h"

typedef struct TreadmillCumulativeDistance
{
	char result[32];
  Api api;
  double speed;
  double time;
} TreadmillCumulativeDistance;

void* TreadmillCumulativeDistance_Create(StatementExecutor* errorHandler, SlimList* args)
{
	TreadmillCumulativeDistance* self = (TreadmillCumulativeDistance*)malloc(sizeof(TreadmillCumulativeDistance));
	memset(self, 0, sizeof(TreadmillCumulativeDistance));
  self->api = Api_Create();
	return self;
}

void TreadmillCumulativeDistance_Destroy(void* void_self)
{
	TreadmillCumulativeDistance* self = (TreadmillCumulativeDistance*)void_self;
  Api_Destroy(self->api);
	free(self);
}

static char* execute(void* void_self, SlimList *args) {
	TreadmillCumulativeDistance* self = (TreadmillCumulativeDistance*)void_self;
  Api_SetTargetSpeed(self->api, self->speed);
  uptimeMillis += self->time;
  return "";
}

static char* setSpeed(void* void_self, SlimList *args) {
	TreadmillCumulativeDistance* self = (TreadmillCumulativeDistance*)void_self;
  self->speed = SlimList_GetDoubleAt(args, 0);
  return "";
}

static char* setTime(void* void_self, SlimList *args) {
	TreadmillCumulativeDistance* self = (TreadmillCumulativeDistance*)void_self;
  double minutes = SlimList_GetDoubleAt(args, 0);
  self->time = minutes*60*1000;
  return "";
}

static char* distance(void* void_self, SlimList *args) {
	TreadmillCumulativeDistance* self = (TreadmillCumulativeDistance*)void_self;
  double d = Api_DistanceTravelled(self->api);
	ftoa(self->result, d, 1);
	return self->result;
}

SLIM_CREATE_FIXTURE(TreadmillCumulativeDistance)
	SLIM_FUNCTION(setSpeed)
	SLIM_FUNCTION(setTime)
	SLIM_FUNCTION(distance)
	SLIM_FUNCTION(execute)
SLIM_END
