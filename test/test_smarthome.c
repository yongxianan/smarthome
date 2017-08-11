#include "unity.h"
#include "smarthome.h"
#include "mock_getgpscoordinate2.h"
void setUp(void)
{
}

void tearDown(void)
{
}

GpsCoordinate within_2000_HouseC = {
	220,
	5400,
};
GpsCoordinate within_5_Outside_Garage_Door = {
	221,
	5300,
};

GpsCoordinate outside_2km_house = {
	2221,
	5345,
};

void test_2km_turn_on_water_heater_aircond(void)
{
		getGpsCoordinate_ExpectAndReturn(within_2000_HouseC);
		turn_Expect(KITCHEN_LIGHT,ON);
		turn_Expect(GARAGE_DOOR,OFF);
		turn_Expect(AIRCOND,ON);
		turn_Expect(WATER_HEATER,ON);
		doSmartThings();
}

void test_5m_turn_on_garage_door(void)
{
		getGpsCoordinate_ExpectAndReturn(within_5_Outside_Garage_Door);
		turn_Expect(KITCHEN_LIGHT,OFF);
		turn_Expect(GARAGE_DOOR,ON);
		turn_Expect(AIRCOND,ON);
		turn_Expect(WATER_HEATER,ON);
		doSmartThings();
}

void test_2km_turn_off_aircond(void)
{
		getGpsCoordinate_ExpectAndReturn(outside_2km_house);
		turn_Expect(KITCHEN_LIGHT,OFF);
		turn_Expect(GARAGE_DOOR,OFF);
		turn_Expect(AIRCOND,OFF);
		turn_Expect(WATER_HEATER,OFF);
		doSmartThings();
}