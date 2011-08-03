#include "Pwm.h"
#include <TimerOne.h>
const char PWM_PIN = 9;
void Pwm_Create(void)
{
  Timer1.initialize(50000);
  Timer1.pwm(PWM_PIN, 0, 50000);
}

void Pwm_Destroy(void)
{
  Pwm_Stop();
}

void Pwm_Start(void)
{
  Timer1.start();
}

void Pwm_Stop(void)
{
  Timer1.stop();
}

void Pwm_SetDutyCycle(double percent)
{
  Timer1.setPwmDuty(PWM_PIN, percent * 1024);
}

void Pwm_SetPeriod(int us)
{
  Timer1.setPeriod(PWM_PIN, us);
}
