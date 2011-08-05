extern "C"
{
#include "hardware/FakeUptime.h"
}

//CppUTest includes should be after your and system includes
#include "CppUTest/TestHarness.h"

TEST_GROUP(Uptime)
{
    void setup()
    {
      Uptime_Create();
    }

    void teardown()
    {
       Uptime_Destroy();
    }
};

TEST(Uptime, ItStartsAtZero)
{
  LONGS_EQUAL(0, Uptime_MilliSeconds() );
}

TEST(Uptime, ItSetFakeUptime)
{
  uptimeMillis = 12543;
  LONGS_EQUAL(12543, Uptime_MilliSeconds() );
}
