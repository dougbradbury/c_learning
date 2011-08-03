#include "FakePwm.h"

int FakePwm_isRunning = 0;
double FakePwm_dutyCycle = 0.0;
int FakePwm_period = 0;

void Pwm_Create(void)
{
}

void Pwm_Destroy(void)
{
}

void Pwm_Start(void)
{
  FakePwm_isRunning = 1;
}

void Pwm_Stop(void)
{
  FakePwm_isRunning = 0;
}

void Pwm_SetDutyCycle(double percent)
{
  FakePwm_dutyCycle = percent;
}

void Pwm_SetPeriod(int us)
{
  FakePwm_period = us;
}
