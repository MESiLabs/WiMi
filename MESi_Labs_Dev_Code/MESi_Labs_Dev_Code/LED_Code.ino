

void changeLED(uint32_t color)
{
	for (int i = 0; i< LED_COUNT; i++)
	{
		leds.setPixelColor(i,color);
	}
	leds.show();
}

void updateLED()
{
	changeLED(colors[current_status]);
}


void cycleLED()
{
	changeLED(red);
	delay(2000);
	changeLED(orange);
	delay(2000);
	changeLED(yellow);
	delay(2000);
	changeLED(green);
	delay(2000);
	changeLED(blue);
	delay(2000);
	changeLED(other);
	delay(2000);
}

