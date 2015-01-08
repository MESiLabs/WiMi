
void serialEvent3()
{
	char dat = Serial3.read();
	Serial.print(dat);
}


void transmitID()
{
	
}

void transmitStatus()
{
	Serial.println("Transmitting Status");
	Serial3.print(current_status);
}

void transmitError()
{
	
}

void transmitMiceData()
{
	
}

void transmitSensorData()
{
	
}

void transmitCageConfig()
{
	
}

void receiveCommand()
{
	
}

void receiveID()
{
	
}

void receiveCageConfig()
{
	
}

void receiveTime()
{
	
}

boolean transmitACK()
{
	
}

boolean receiveACK()
{
	
}