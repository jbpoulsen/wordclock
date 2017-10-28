#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <FastLED.h>
#define NUM_LEDS 144
#define DATA_PIN 5

int BRIGHTNESS = 80;
CRGB leds[NUM_LEDS];
tmElements_t tm;

boolean bol = false;

//Actual words as array variables
int WordIts[] = {132, 133, 134};
int WordAbout[] = {136, 137, 138, 139, 140};
int WordTwenty[] = {131, 130, 129, 128, 127, 126};
int WordMinTen[] = {124, 123, 122};
int WordMinFive[] = {108, 109, 110, 111};
int WordQuarter[] = {113, 114, 115, 116, 117, 118, 119};
int WordMinutes[] = {107, 106, 105, 104, 103, 102, 101};
int WordHalf[] = {100, 99, 98, 97};
int WordTo[] = {84, 85};
int WordPast[] = {86, 87, 88, 89};
int WordFive[] = {91, 92, 93, 94};
int WordOne[] = {83, 82, 81};
int WordTwo[] = {80, 79, 78};
int WordThree[] = {77, 76, 75, 74, 73};
int WordFour[] = {60, 61, 62, 63};
int WordSix[] = {64, 65, 66};
int WordSeven[] = {67, 68, 69, 70, 71};
int WordEight[] = {59, 58, 57, 56, 55};
int WordNine[] = {54, 53, 52, 51};
int WordTen[] = {50, 49, 48};
int WordEleven[] = {36, 37, 38, 39, 40, 41};
int WordTwelve[] = {42, 43, 44, 45, 46, 47};
int WordOclock[] = {35, 34, 33, 32, 31, 30};
int WordTime[] = {28, 27, 26, 25};
int WordFor[] = {12,13,14};
int WordA[] = {16};
int WordCoffee[] = {18, 19, 20, 21, 22, 23};
int WordTea[] = {11, 10, 9};
int WordLunch[] = {8, 7, 6, 5, 4};
int WordHome[] = {4, 3, 2, 1, 0};

// To enable function with optional parameters
void setBrightness(int brightness = BRIGHTNESS);

void setup() {
  clear();
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);  
  setBrightness();
}

void loop() {
  /*
  getTime();
  clear();
  delay(1000);

  if(bol)
  {
    lightup(WordIts, CRGB::Blue);
    lightup(WordMinTen, CRGB::Blue);
    lightup(WordMinutes, CRGB::Blue);
    lightup(WordPast, CRGB::Blue);
    lightup(WordSeven, CRGB::Blue);
  }
  else
  {
    lightup(WordIts, CRGB::Blue);
    lightup(WordMinTen, CRGB::Blue);
    lightup(WordMinutes, CRGB::Blue);
    lightup(WordPast, CRGB::Blue);
    lightup(WordEleven, CRGB::Blue);  
  }
  
  bol = !bol;
  FastLED.show();

  */
   
  for(int dot = 0; dot < NUM_LEDS; dot++) { 
    leds[dot] = CRGB::White;
    leds[dot+1] = CRGB::White;
    leds[dot+2] = CRGB::White;
    leds[dot+3] = CRGB::White;
    FastLED.show();
    // clear this led for the next time around the loop
    leds[dot] = CRGB::Black;
    leds[dot+1] = CRGB::Black;
    leds[dot+2] = CRGB::Black;
    leds[dot+3] = CRGB::Black;
    delay(500);
  }
  
  
}

void lightup(int word[], CRGB color) {
  for (int x = 0; x <= sizeof(word) ; x++) {    
    leds[word[x]] = color;
  }
}

void clear()
{
  FastLED.clear();
}

void setBrightness(int brightness)
{
  BRIGHTNESS = brightness;
  FastLED.setBrightness(brightness);
}

void getTime()
{
  if (RTC.read(tm)) {
    Serial.print("Ok, Time = ");
    print2digits(tm.Hour);
    Serial.write(':');
    print2digits(tm.Minute);
    Serial.write(':');
    print2digits(tm.Second);
    Serial.print(", Date (D/M/Y) = ");
    Serial.print(tm.Day);
    Serial.write('/');
    Serial.print(tm.Month);
    Serial.write('/');
    Serial.print(tmYearToCalendar(tm.Year));
    Serial.println();
  } else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      Serial.println();
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      Serial.println();
    }
  }
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}

