#include <Wire.h>
void eepromWrite(byte highAdd, byte lowAdd, byte data)
{
	Wire.beginTransmission(EEPROM_ADD);
	Wire.write(highAdd);
	Wire.write(lowAdd);
	Wire.write(data);
	Wire.endTransmission();
}

byte eepromRead(byte highAdd, byte lowAdd)
{
	Wire.beginTransmission(EEPROM_ADD);
	Wire.write(highAdd);
	Wire.write(lowAdd);
	Wire.endTransmission();
	
	Wire.requestFrom(EEPROM_ADD,1);
	while(!Wire.available());
	return Wire.read();
}