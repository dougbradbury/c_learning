#ifndef D_FakePwm_H
#define D_FakePwm_H

/**********************************************************
 *
 * FakePwm is responsible for providing a
 * test stub for Pwm
 *
 **********************************************************/

#include "Pwm.h"

extern int FakePwm_isRunning;
extern int FakePwm_period;
extern double FakePwm_dutyCycle;

#endif  /* D_FakePwm_H */
