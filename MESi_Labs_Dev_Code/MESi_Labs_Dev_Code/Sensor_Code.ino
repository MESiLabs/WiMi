
void readDHT(float &temperature, float &humidity)
{
	DHT.read22(DHT_PIN);			// Read values from Sensor
	temperature = DHT.temperature;	// Assign temperature value to variable
	humidity = DHT.humidity;		// Assign humidity value to variable
}


void readSensors()
{
	float temperature, humidity;
	double lux;
	readDHT(temperature,humidity);
	readTSL(lux);
	/*Serial.print("Current Temperature:\t");
	Serial.print(temperature,1);
	Serial.write(176);
	Serial.println("C");
	Serial.print("Current Humidity:\t");
	Serial.print(humidity,1);
	Serial.println("%");
	Serial.print("Current Lux Value:\t");
	Serial.println(lux);*/
	writeSensorSD(temperature,humidity,lux);
	
	scheduler.schedule(readSensors,10*SCHEDULE_WAIT);
}

void readTSL(double &lux)
{
	unsigned data0, data1;
	if(TSL.getData(data0,data1))
	{
		boolean good;
		good = TSL.getLux(0,TSL_WAIT,data0,data1,lux);
		
		upperThreshold = data0 + (TSLthreshold/100 * data0);
		lowerThreshold = data0 - (TSLthreshold/100 * data0);
		
		//light.clearInterrupt();
	}
	else
	{
		lux = -1;
		byte error = TSL.getError();
		printError(error);
	}
}