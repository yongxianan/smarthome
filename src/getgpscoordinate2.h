#ifndef _GETGPSCOORDINATE2_H
#define _GETGPSCOORDINATE2_H

typedef struct GpsCoordinate GpsCoordinate;

struct GpsCoordinate {
  float x;
  float y;   
};
 
GpsCoordinate getGpsCoordinate();

typedef enum {
  GARAGE_DOOR,
  KITCHEN_LIGHT,
  AIRCOND,
  WATER_HEATER,
} Device;

typedef enum {
  OFF,
  ON
} State;

void turn(Device device, State state);

#endif // _GETGPSCOORDINATE2_H
