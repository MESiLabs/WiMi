byte current_status = 0;
byte myAddress;

SFE_TSL2561 TSL;
dht DHT;					// Variable name for reading sensor data
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, LED, NEO_GRB + NEO_KHZ800);
RTC_clock rtc_clock(XTAL);   // on board RTC for time keeping purposes
RTC_DS1307 rtc;              // Real time clock to get accurate timestamps

uint32_t black = leds.Color(0, 0, 0);
uint32_t red = leds.Color(255, 0, 0);
uint32_t orange = leds.Color(255, 102, 0);
uint32_t yellow = leds.Color(255, 255, 0);
uint32_t green = leds.Color(0, 255, 0);
uint32_t blue = leds.Color(0, 0, 255);
uint32_t other = leds.Color(255, 255, 255);

uint32_t colors[] = {black, red, orange, yellow, green, blue, other};
	
byte TSLpersist, TSLcontrol, TSLthreshold;