/*
@Author: Bilel OURAL
@Version: 0.1
@License: GNU v3
@Description: Read a Joystick control Position on an Arduino board
*/

#ifndef JOYSintICKCintRL_H_INCLUDED
#define JOYSintICKCintRL_H_INCLUDED

#include "Arduino.h"


/**
* Class JoystickControl
* Joystick Control that gives its position in int
*/
class JoystickControl{



public:
	/**
	* Defining a State Structure that will hold the Joystick data
	*/
	struct JoystickState {
		int X;
		int Y;
		bool SW;
	};
	
	/**
	* Constructor CintOR1
	* Construct the control with the minimum requirement
	* int const& minVal: inthe minimum value that the joystick can return according to the constructor specifications
	* int const& maxVal: inthe maximum value that the joystick can return according to the constructor specifications
	* int const& pinX: Analog slot inside which the VrX pin is plugged
	* int const& pinY: Analog slot inside which the VrY pin is plugged
	* int const& pinSW: Analog slot inside which the SW pin is plugged
	*/
	JoystickControl(int const& minVal, int const& maxVal, int const& pinX, int const& pinY, int const& pinSW);
	
	/**
	* Constructor CintOR2
	* Construct the control with an automated unique mapping for both X and Y coordinates
	* int const& minVal: inthe minimum value that the joystick can return according to the constructor specifications
	* int const& maxVal: inthe maximum value that the joystick can return according to the constructor specifications
	* int const& pinX: Analog slot inside which the VrX pin is plugged
	* int const& pinY: Analog slot inside which the VrY pin is plugged
	* int const& pinSW: Analog slot inside which the SW pin is plugged
	* int const& mapLow: Minimum expected mapped value for getting the position
	* int const& mapHigh: Maximum expected mapped value for getting the position
	*/
    JoystickControl(int const& minVal, int const& maxVal, int const& pinX, int const& pinY, int const& pinSW, int const& mapLow, int const& mapHigh);
	
	/**
	* Constructor CintOR3
	* Construct the control with an automated mapping independently set for X coordinates and Y coordinates
	* int const& minVal: inthe minimum value that the joystick can return according to the constructor specifications
	* int const& maxVal: inthe maximum value that the joystick can return according to the constructor specifications
	* int const& pinX: Analog slot inside which the VrX pin is plugged
	* int const& pinY: Analog slot inside which the VrY pin is plugged
	* int const& pinSW: Analog slot inside which the SW pin is plugged
	* int const& mapLowX: Minimum expected mapped value for getting the X position
	* int const& mapHighX: Maximum expected mapped value for getting the X position
	* int const& mapLowY: Minimum expected mapped value for getting the Y position
	* int const& mapHighY: Maximum expected mapped value for getting the Y position
	*/
    JoystickControl(int const& minVal, int const& maxVal, int const& pinX, int const& pinY, int const& pinSW, int const& mapLowX, int const& mapHighX, int const& mapLowY, int const& mapHighY);
		
	/**
	* Method that returns the X position (mapped or not depending on instantiation parameters)
	*/
	int getX() const;

			
	/**
	* Method that returns the Y position (mapped or not depending on instantiation parameters)
	*/
	int getY() const;
			
	/**
	* Method that returns the Z position (mapped or not depending on instantiation parameters)
	*/
	int getZ() const;
	
			
	/**
	* Returns both the X and Y position (mapped or not depending on instantiation parameters)
	* through a JoystickState struct
	*/	
	JoystickState getState();

	
private:
    bool mappingEnabled; //Class must return mapped values or original ones (Auto-initialized by the constructor)
    int pinX; //Stores the X pos pin
    int pinY; //Stores the X pos pin
    int pinSW; //Stores the SW pos pin
    int minVal; //Stores the minimum Joystick expected read value
    int maxVal; //Stores the maximum Joystick expected read value
    int mapLowX; //Stores the minimum X expected (mapped value)
    int mapLowY; //Stores the minimum Y expected (mapped value)
    int mapHighX; //Stores the maximum X expected (mapped value)
    int mapHighY; //Stores the maximum Y expected (mapped value)
};


#endif // JOYSintICKCintRL_H_INCLUDED
