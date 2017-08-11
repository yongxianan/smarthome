#include "smarthome.h"
#include <math.h>
#include "getgpscoordinate2.h"
#include <stdio.h>

GpsCoordinate kitchen={
	196,
	5400,
	};
GpsCoordinate house={
	200,
	5345,
	};
GpsCoordinate garage_door={
	220,
	5300,
	};
GpsCoordinate garage={
	215,
	5300,
	};


void doSmartThings(){
	float x,y;
	GpsCoordinate xandy;
	xandy=getGpsCoordinate();
	x=xandy.x;
	y=xandy.y;
	if(sqrt(pow(x - kitchen.x,2)+pow(y - kitchen.y,2))<=50.0){
		printf("enter");
		turn(KITCHEN_LIGHT, ON);
	}
	else
		turn(KITCHEN_LIGHT, OFF);
	
	if(sqrt(pow(x - garage_door.x,2)+pow(y - garage_door.y,2))<=5.0 &&
	 sqrt(pow(x - garage.x,2)-pow(y - garage.y,2))>5.0)
		turn(GARAGE_DOOR, ON);
	else
		turn(GARAGE_DOOR, OFF);
	
	
	if(sqrt(pow(x - house.x,2)+pow(y - house.y,2))<=2000.0){
		turn(AIRCOND, ON);
		turn(WATER_HEATER, ON);
	}
	else{
		turn(AIRCOND, OFF);
		turn(WATER_HEATER, OFF);
	}
	
	
	
}

