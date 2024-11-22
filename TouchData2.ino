#include <Adafruit_DotStar.h>
// Because conditional #includes don't work w/Arduino sketches...
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
//#include <avr/power.h> // ENABLE THIS LINE FOR GEMMA OR TRINKET


#define TOUCHDATAPIN2 7
#define DATAPIN    4    // Light Green Wire
#define CLOCKPIN   5    // Light Yellow Wire
#define MAXBRIGHTNESS 150
#define MINBRIGHTNESS 30
Adafruit_DotStar strip(NUMPIXELS, DATAPIN, CLOCKPIN);
int currentState;
int lastState = LOW;
int ledState = LOW;
int ledColor = 4;
int BlinkingState = 0;
int touches = 0;
int timeAfterHold = -1;
int timeAfterTouch = -1;
int currentBrightness = 150;



void setup() {
  pinMode(TOUCHDATAPIN,INPUT);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);
}

void loop(){

  currentState = digitalRead(TOUCHDATAPIN2);

     void blinking(){
         int Brightness = strip.getBrightness;
         while (BlinkingState = 1){
         strip.setBrightness(Brightness);
         strip.show();
         strip.setBrightness(0);
         }
         //



