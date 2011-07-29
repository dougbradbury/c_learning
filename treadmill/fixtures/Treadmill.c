#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "Fixtures.h"
#include "SlimList.h"

typedef struct Treadmill
{
	char result[32];
} Treadmill;

void* Treadmill_Create(StatementExecutor* errorHandler, SlimList* args)
{
	Treadmill* self = (Treadmill*)malloc(sizeof(Treadmill));
	memset(self, 0, sizeof(Treadmill));
	return self;
}

void Treadmill_Destroy(void* self)
{
	free(self);
}

static char* givenTreadmillSpeed(void* void_self, SlimList* args) {
	Treadmill* self = (Treadmill*)void_self;
	return "";
}

static char* incrementSpeed(void* void_self, SlimList* args) {
	Treadmill* self = (Treadmill*)void_self;
	return "";
}

static char* targetSpeed(void* void_self, SlimList* args) {
	Treadmill* self = (Treadmill*)void_self;
	snprintf(self->result, 32, "%f", 1.0f);
	return self->result;
}

SLIM_CREATE_FIXTURE(Treadmill)
	SLIM_FUNCTION(givenTreadmillSpeed)
	SLIM_FUNCTION(incrementSpeed)
	SLIM_FUNCTION(targetSpeed)
SLIM_END

