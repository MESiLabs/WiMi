#include <SFE_TSL2561.h>
#include <dht.h>
#include <RTClib.h>
#include <rtc_clock.h>
#include <Wire.h>
#include <SPI.h>
#include <SD_Ada/SD.h>
#include <Scheduler.h>
#include <Adafruit_NeoPixel.h>
#include "Pins.h"	// Pin List of all connected components
#include "Constants.h"	// Constant values for use in all code
#include "Error_List.h"
/*
 * MESi_Labs_Dev_Code.ino
 *
 * Created: 1/5/2015 12:10:21 PM
 * Author: Cody
 */ 

Scheduler scheduler = Scheduler();

void setup()
{
	initialize();
	displayInfo();
	readSensors();
	//cycleLED();
	  /* add setup code here, setup code runs once when the processor starts */
}

void loop()
{
	scheduler.update();
	/* add main program code here, this code starts again each time it ends */

}


