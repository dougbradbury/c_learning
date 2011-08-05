#include "Uptime.h"
int uptimeMillis;

void Uptime_Create(void)
{
  uptimeMillis = 0;
}

long Uptime_MilliSeconds(void)
{
  return uptimeMillis;
}

void Uptime_Destroy(void){}
