
//insert changes whenever

void initialize()
{
	Serial.begin(DEBUG_BAUD);	// Setup Serial port for debugging
	Wire.begin();
	init_LEDS();
	init_EEPROM();
	init_XBee();
	init_Sensors();
	init_SD();
	current_status = 1;
	
	init_RTC();
	updateLED();
}


void init_Sensors()
{
	init_TSL();
}

void init_LEDS()
{
	leds.begin();
	delayMicroseconds(250);
	changeLED(black);
	leds.show();
	leds.setBrightness(32);
}

void init_SD()
{
	/*------------Initialize SD card for data logging----------*/
	pinMode(SD_CS, OUTPUT);
	if (SD.begin(SD_CS, SD_MOSI, SD_MISO, SD_CLK))
	{
		Serial.println("SD Card Working");
	}
	else
	{
		Error(SD_INIT_ERROR, "SD begin failed to Initialized");
	}
	
	
	/*if (!card.init(SPI_HALF_SPEED, SD_CS, SD_MOSI, SD_MISO, SD_CLK)) {
		Error(SD_INIT_ERROR, "SD begin failed to Initialized.");
	}*/
}

void init_EEPROM()
{
	
	myAddress = eepromRead(0,0);
}

void init_TSL()
{
	boolean gain = 0;     // Gain setting, 0 = X1, 1 = X16;
	unsigned int ms;  // Integration ("shutter") time in milliseconds
	unsigned char time = 2;
	
	TSL.begin(0x29);
	TSL.setTiming(gain,time,ms);
	TSL.setPowerUp();
	TSL.setInterruptControl(TSLcontrol,TSLpersist);
	//attachInterrupt(TSL_INT,readTSL,FALLING);

}

void init_RTC()
{
	rtc.begin();
	if(!rtc.isrunning())
	{
		Error(4,"RTC not working!");
	}
	calibrateRTC();
}

void init_XBee()
{
	Serial3.begin(XBEE_BAUD);
	pinMode(XB_IO1, OUTPUT);
	pinMode(XB_IO2, OUTPUT);
	digitalWrite(XB_IO1, LOW);
	digitalWrite(XB_IO2, LOW);
}

void init_RFID()
{
	Serial1.begin(RFID_BAUD);
	Serial2.begin(RFID_BAUD);
}
