extern "C"
{
#include "Api.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(Api)
{
	Api api;

	void setup()
	{
		api = Api_Create();
	}

	void teardown()
	{
		Api_Destroy(api);
  }
  void SpeedIs(double speed)
  {
    DOUBLES_EQUAL(Api_GetTargetSpeed(api), speed, 0.01);
  }
};


TEST(Api, ItStatsAtZeroSpeed)
{
  SpeedIs(0.0);
}

TEST(Api, itSetsTheTargetSpeed)
{
  Api_SetTargetSpeed(api, 1.0);
  SpeedIs(1.0);
}

TEST(Api, itIncrementsTheTargetSpeed)
{
  Api_SetTargetSpeed(api, 1.0);
  Api_IncrementTargetSpeed(api);
  SpeedIs(1.1);
}

TEST(Api, itDecrementsTheTargetSpeed)
{
  Api_SetTargetSpeed(api, 1.0);
  Api_DecrementTargetSpeed(api);
  SpeedIs(0.9);
}

TEST(Api, itHasMaxSpeed)
{
  Api_SetTargetSpeed(api, 3.0);
  Api_SetMaximumSpeed(api, 3.0);
  Api_IncrementTargetSpeed(api);
  SpeedIs(3.0);
}
