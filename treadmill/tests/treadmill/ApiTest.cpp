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
};

TEST(Api, ItStatsAtZeroSpeed)
{
	DOUBLES_EQUAL(Api_GetTargetSpeed(api), 0.0, 0.1);
}

TEST(Api, itSetsTheTargetSpeed)
{
  Api_SetTargetSpeed(api, 1.0);
	DOUBLES_EQUAL(Api_GetTargetSpeed(api), 1.0, 0.1);
}

TEST(Api, itIncrementsTheTargetSpeed)
{
  Api_SetTargetSpeed(api, 1.0);
  Api_IncrementTargetSpeed(api);
  DOUBLES_EQUAL(Api_GetTargetSpeed(api), 1.1, 0.1);
}

