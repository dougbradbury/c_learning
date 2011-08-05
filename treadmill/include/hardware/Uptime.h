#ifndef D_Uptime_H
#define D_Uptime_H

/**********************************************************
 *
 * Uptime is responsible for providing an abstraction to
 * the system uptime
 *
 **********************************************************/

void Uptime_Create(void);
void Uptime_Destroy(void);
long Uptime_MilliSeconds(void);
#endif  /* D_Uptime_H */