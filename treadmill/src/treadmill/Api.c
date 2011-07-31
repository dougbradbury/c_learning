#include "Api.h"
#include <stdlib.h>
#include <memory.h>

typedef struct ApiStruct
{
    double targetSpeed;
} ApiStruct;

Api Api_Create(void)
{
     Api self = calloc(1, sizeof(ApiStruct));
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
  self->targetSpeed += 0.1;
}
