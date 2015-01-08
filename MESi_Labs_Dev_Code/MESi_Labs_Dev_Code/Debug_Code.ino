
void Error(byte code, String str)
{
	Serial.println(str);
	current_status = 1;
	updateLED();
}

void displayInfo()
{
	String date, time;
	DateTime now = readRTC();
	convertRTCString(now,date,time);
	
	Serial.print("Node Address:\t");
	Serial.print(myAddress);
	Serial.println("");
	Serial.print("Current Time:\t");
	Serial.println(time);
	Serial.print("Current Date:\t");
	Serial.println(date);
	Serial.print("Status Code:\t");
	Serial.print(current_status);
	Serial.println("");
	Serial.print("RFID 1 Status:\t");
	Serial.print("Not Connected");
	Serial.println("");
	Serial.print("RFID 2 Status:\t");
	Serial.print("Not Connected");
	Serial.println("");
	
}

void printError(byte error)
// If there's an I2C error, this function will
// print out an explanation.
{
	Serial.print("I2C error: ");
	Serial.print(error,DEC);
	Serial.print(", ");
	
	switch(error)
	{
		case 0:
		Serial.println("success");
		break;
		case 1:
		Serial.println("data too long for transmit buffer");
		break;
		case 2:
		Serial.println("received NACK on address (disconnected?)");
		break;
		case 3:
		Serial.println("received NACK on data");
		break;
		case 4:
		Serial.println("other error");
		break;
		default:
		Serial.println("unknown error");
	}
}

void serialEvent()
{
	char cmd = Serial.read();
	executeDebugCMD(cmd);
}


void executeDebugCMD(char command)
{
	switch(command)
	{
		case 'D':
			transmitStatus();
			break;
		default:
			Serial.println("Command not valid.");
			break;
	}
}