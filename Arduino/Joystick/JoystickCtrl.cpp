/*
@Author: Bilel OURAL
@Version: 0.1
@License: GNU v3
@Description: Read a Joystick control Position on an Arduino board
*/

#include "JoystickCtrl.h"

JoystickControl::JoystickControl(int const& minVal, int const& maxVal, int const& pinX, int const& pinY, int const& pinSW):minVal(minVal), maxVal(maxVal), pinX(pinX), pinY(pinY), pinSW(pinSW), mappingEnabled(false){
};
	
JoystickControl::JoystickControl(int const& minVal, int const& maxVal, int const& pinX, int const& pinY, int const& pinSW, int const& mapLow, int const& mapHigh):minVal(minVal), maxVal(maxVal), pinX(pinX), pinY(pinY), pinSW(pinSW), mapLowX(mapLow), mapLowY(mapLow), mapHighX(mapHigh), mapHighY(mapHigh), mappingEnabled(true){
};
	
JoystickControl::JoystickControl(int const& minVal, int const& maxVal, int const& pinX, int const& pinY, int const& pinSW, int const& mapLowX, int const& mapHighX, int const& mapLowY, int const& mapHighY):minVal(minVal), maxVal(maxVal), pinX(pinX), pinY(pinY), pinSW(pinSW), mapLowX(mapLowX), mapLowY(mapLowY), mapHighX(mapHighX), mapHighY(mapHighY), mappingEnabled(true){
};
		

int JoystickControl::getX() const
{
	return (int) (mappingEnabled?map(analogRead(pinX), minVal, maxVal, mapLowX, mapHighX):analogRead(pinX));
}

		
int JoystickControl::getY() const
{
	return (int) (mappingEnabled?map(analogRead(pinY), minVal, maxVal, mapLowY, mapHighY):analogRead(pinY));
}

		
int JoystickControl::getZ() const
{
	return (int) (analogRead(pinSW));
}
	

JoystickControl::JoystickState JoystickControl::getState()
{
	JoystickState point;
	point.X = getX();
	point.Y = getY();
	point.SW = (getZ()==0)?true:false;
	return point;
}
