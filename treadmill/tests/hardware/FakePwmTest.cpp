extern "C"
{
#include "FakePwm.h"
}

//CppUTest includes should be after your and system includes
#include "CppUTest/TestHarness.h"

TEST_GROUP(Pwm)
{
    void setup()
    {
      Pwm_Create();
    }

    void teardown()
    {
       Pwm_Destroy();
    }
};

TEST(Pwm, Create)
{
  Pwm_Start();
  CHECK(FakePwm_isRunning)
}

TEST(Pwm, SetDuty)
{
  Pwm_SetDutyCycle(0.25);
  DOUBLES_EQUAL(FakePwm_dutyCycle, 0.25, 0.01);
}

TEST(Pwm, SetPeriod)
{
  Pwm_SetPeriod(5);
  LONGS_EQUAL(FakePwm_period, 5);
}

TEST(Pwm, Stop)
{
  Pwm_Start();
  Pwm_Stop();
  CHECK(!FakePwm_isRunning);
}
