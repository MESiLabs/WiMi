/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino Due (Programming Port), Platform=sam, Package=arduino
*/

#define __SAM3X8E__
#define USB_VID 0x2341
#define USB_PID 0x003e
#define USBCON
#define USB_MANUFACTURER "\"Unknown\""
#define USB_PRODUCT "\"Arduino Due\""
#define ARDUINO 155
#define ARDUINO_MAIN
#define F_CPU 84000000L
#define printf iprintf
#define __SAM__
extern "C" void __cxa_pure_virtual() {;}

//
//
void Error(byte code, String str);
void displayInfo();
void printError(byte error);
void serialEvent();
void executeDebugCMD(char command);
void eepromWrite(byte highAdd, byte lowAdd, byte data);
byte eepromRead(byte highAdd, byte lowAdd);
void changeLED(uint32_t color);
void updateLED();
void cycleLED();
DateTime readRTC();
void convertRTCString(DateTime dt, String &date, String &time);
void calibrateRTC();
void writeSensorSD(float temp, float hum, double lux);
void readDHT(float &temperature, float &humidity);
void readSensors();
void readTSL(double &lux);
void initialize();
void init_Sensors();
void init_LEDS();
void init_SD();
void init_EEPROM();
void init_TSL();
void init_RTC();
void init_XBee();
void init_RFID();
void serialEvent3();
void transmitID();
void transmitStatus();
void transmitError();
void transmitMiceData();
void transmitSensorData();
void transmitCageConfig();
void receiveCommand();
void receiveID();
void receiveCageConfig();
void receiveTime();
boolean transmitACK();
boolean receiveACK();

#include "C:\Users\Cody\Google Drive\MESi Labs\Software\Arduino IDE\Arduino-1.5.5-r2\hardware\arduino\sam\variants\arduino_due_x\pins_arduino.h" 
#include "C:\Users\Cody\Google Drive\MESi Labs\Software\Arduino IDE\Arduino-1.5.5-r2\hardware\arduino\sam\variants\arduino_due_x\variant.h" 
#include "C:\Users\Cody\Google Drive\MESi Labs\Software\Arduino IDE\Arduino-1.5.5-r2\hardware\arduino\sam\cores\arduino\arduino.h"
#include "C:\Users\Cody\Google Drive\MESi Labs\Software\Atmel_Studio\MESi_Labs_Dev_Code\MESi_Labs_Dev_Code\MESi_Labs_Dev_Code.ino"
#include "C:\Users\Cody\Google Drive\MESi Labs\Software\Atmel_Studio\MESi_Labs_Dev_Code\MESi_Labs_Dev_Code\All_Globals.ino"
#include "C:\Users\Cody\Google Drive\MESi Labs\Software\Atmel_Studio\MESi_Labs_Dev_Code\MESi_Labs_Dev_Code\Constants.h"
#include "C:\Users\Cody\Google Drive\MESi Labs\Software\Atmel_Studio\MESi_Labs_Dev_Code\MESi_Labs_Dev_Code\Debug_Code.ino"
#include "C:\Users\Cody\Google Drive\MESi Labs\Software\Atmel_Studio\MESi_Labs_Dev_Code\MESi_Labs_Dev_Code\EEPROM.ino"
#include "C:\Users\Cody\Google Drive\MESi Labs\Software\Atmel_Studio\MESi_Labs_Dev_Code\MESi_Labs_Dev_Code\Error_List.h"
#include "C:\Users\Cody\Google Drive\MESi Labs\Software\Atmel_Studio\MESi_Labs_Dev_Code\MESi_Labs_Dev_Code\LED_Code.ino"
#include "C:\Users\Cody\Google Drive\MESi Labs\Software\Atmel_Studio\MESi_Labs_Dev_Code\MESi_Labs_Dev_Code\Pins.h"
#include "C:\Users\Cody\Google Drive\MESi Labs\Software\Atmel_Studio\MESi_Labs_Dev_Code\MESi_Labs_Dev_Code\RTC_Code.ino"
#include "C:\Users\Cody\Google Drive\MESi Labs\Software\Atmel_Studio\MESi_Labs_Dev_Code\MESi_Labs_Dev_Code\SD_Code.ino"
#include "C:\Users\Cody\Google Drive\MESi Labs\Software\Atmel_Studio\MESi_Labs_Dev_Code\MESi_Labs_Dev_Code\Sensor_Code.ino"
#include "C:\Users\Cody\Google Drive\MESi Labs\Software\Atmel_Studio\MESi_Labs_Dev_Code\MESi_Labs_Dev_Code\Startup_Code.ino"
#include "C:\Users\Cody\Google Drive\MESi Labs\Software\Atmel_Studio\MESi_Labs_Dev_Code\MESi_Labs_Dev_Code\XBee_Code.ino"
