#ifndef D_Pwm_H
#define D_Pwm_H

void Pwm_Create(void);
void Pwm_Destroy(void);

void Pwm_Start();
void Pwm_Stop();
void Pwm_SetDutyCycle(double percent);
void Pwm_SetPeriod(int microseconds);
#endif  /* D_Pwm_H */
