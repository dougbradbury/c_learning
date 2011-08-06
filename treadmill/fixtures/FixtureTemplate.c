#include <stdlib.h>
#include <stdio.h>
#include "Fixtures.h"
#include "SlimList.h"

typedef struct ExampleFixture
{
	char result[32];
} ExampleFixture;

void* ExampleFixture_Create(StatementExecutor* errorHandler, SlimList* args)
{
	ExampleFixture* self = (ExampleFixture*)malloc(sizeof(ExampleFixture));
	memset(self, 0, sizeof(ExampleFixture));
	return self;
}

void ExampleFixture_Destroy(void* void_self)
{
	ExampleFixture* self = (ExampleFixture*)void_self;
	free(self);
}

static char* exampleMethod(void* void_self, SlimList* args)
{
	ExampleFixture* self = (ExampleFixture*)void_self;
	return "";
}

SLIM_CREATE_FIXTURE(ExampleFixture)
	SLIM_FUNCTION(exampleMethod)
SLIM_END

