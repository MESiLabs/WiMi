
void writeSensorSD(float temp, float hum, double lux)
{
	File sensors;
	char* sensor_file = "Sensor.csv";
	
	if(SD.exists(sensor_file))
	{
		DateTime current_time = readRTC();
		String date, time;
		convertRTCString(current_time,date,time);
		sensors = SD.open(sensor_file,FILE_WRITE);
		if(sensors)
		{
			sensors.print(date);
			sensors.print(',');
			sensors.print(time);
			sensors.print(',');
			sensors.print(temp);
			sensors.print(',');
			sensors.print(hum);
			sensors.print(',');
			sensors.print(lux);
			sensors.println();
			sensors.close();
		}
	}
	else
	{
		sensors = SD.open(sensor_file, FILE_WRITE);
		if(sensors)
		{
			sensors.println("Date,Time,Temperature,Humidity,Lux");
			sensors.close();
			writeSensorSD(temp,hum,lux);
		}
	}
	
	
}