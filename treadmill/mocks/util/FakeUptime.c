#include "Uptime.h"
int uptimeMillis;

void Uptime_Create(void)
{
  uptimeMillis = 0;
}

void Uptime_Destroy(void)
{
}


long Uptime_MilliSeconds(void)
{
  return uptimeMillis;
}
