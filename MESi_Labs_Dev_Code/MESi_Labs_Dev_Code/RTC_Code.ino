DateTime readRTC()
{
	DateTime t = rtc.now();
	int day, month, year, hour, minute, second, temp;
	day = rtc_clock.get_days();
	month = rtc_clock.get_months();
	year = rtc_clock.get_years();
	hour = rtc_clock.get_hours();
	minute = rtc_clock.get_minutes();
	second = rtc_clock.get_seconds();
	DateTime currentDT = DateTime(year, month, day, hour, minute, second);
	
	return currentDT;
}


void convertRTCString(DateTime dt, String &date, String &time)
{
	String month = String(dt.month());
	String day = String(dt.day());
	String year = String(dt.year());
	String hour = String(dt.hour());
	String minute = String(dt.minute());
	String second = String(dt.second());
	
	date = (month + "/" + day + "/" + year);
	time = (hour +":" + minute + ":" + second);
}

void calibrateRTC()
{
	DateTime now = rtc.now();
	if (now.year() > 2000)	// Check that RTC is functioning
	{
		rtc_clock.set_time(now.hour(), now.minute(), now.second());
		rtc_clock.set_date(now.day(), now.month(), now.year());
	}
	else
	{
		Serial.print("RTC not working");
	}
}