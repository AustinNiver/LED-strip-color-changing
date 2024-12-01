#include <Adafruit_DotStar.h>
#include <SPI.h>

// INPUT PINS
#define TOUCHPIN1 2
#define TOUCHPIN2 7

// OUTPUT PINS
#define DATAPIN   4
#define CLOCKPIN  5

// STRIP DATA
#define NUMPIXELS 72
#define MINBRIGHT 10
#define MAXBRIGHT 20

// INITIALIZE THE STRIP
Adafruit_DotStar strip(NUMPIXELS, DATAPIN, CLOCKPIN);


// INITIALIZE GLOBAL VARS
int touch1 = 0, touch2 = 0;
int last1 = LOW, last2 = LOW;
int detected1 = 0, detected2 = 0;
int timetouch1 = -1, timetouch2 = -1;
int timehold1 = -1, timehold2 = -1;


// INITIALIZE A STRUCT FOR THE STRIP
struct {
  bool isOn = false; 
  bool isBlinking = false;
  bool isRainbow = false;
  int color = 0;
  int brightness = 20;
} ledStrip;


void setup() {
  //INITIALIZE THE INPUT PINS AND START THE STRIP
  pinMode(TOUCHPIN1,INPUT);
  pinMode(TOUCHPIN2,INPUT);
  strip.begin();
  strip.show();
  Serial.begin(9600);
}

void loop() {
  // read both of our sensors
  touch1 = digitalRead(TOUCHPIN1);
  touch2 = digitalRead(TOUCHPIN2);

  if (detected2 == 0){   // IF THE OTHER SENSOR ALREADY DETECTED INPUT IGNORE THIS SENSOR
    switch (touch1) {
      case HIGH:      // DETECTED TOUCH
        switch (last1) {
          case LOW:
            detected1 += 1;
            timetouch1 = 0;
            break;
          case HIGH:  // DETECTED HOLD
            timehold1 += 1;
            break;
        }
        break;
      case LOW:
        switch (last1) {
          case HIGH:
            timehold1 = -1;
            break;
        }
        break;
    }
  }
  
  if (detected1 == 0) {  // IF THE OTHER SENSOR ALREADY DETECTED INPUT IGNORE THIS SENSOR
    switch (touch2) {
      case HIGH:      // DETECTED TOUCH
        switch (last2) {
          case LOW:
            detected2 += 1;
            timetouch2 = 0;
            break;
          case HIGH:  // DETECTED HOLD
            timehold2 += 1;
            break;
        }
        break;
      case LOW:
        switch (last2) {
          case HIGH:
            timehold2 = -1;
            break;
        }
        break;
    }
  }

  if (detected1 > 0) {
    if (timetouch1 > -1){
      timetouch1 += 1;
    }
    if (timehold1 > -1){
      timehold1 += 1;
    }
    if (timetouch1 > 500){
      ProcessTouches(detected1,1);
      detected1 = 0;
      timetouch1 = -1;
      timehold1 = -1;
    }
    if (timehold1 > 400) {
      if (ledStrip.isOn == true) {
        DecreaseBrightness();
        timetouch1 = -1;
        timehold1 = 0;
      }
    }
  }else if (detected2 > 0) {
    if (timetouch2 > -1){
      timetouch2 += 1;
    }
    if (timehold2 > -1){
      timehold2 += 1;
    }
    if (timetouch2 > 500){
      ProcessTouches(detected2,2);
      detected2 = 0;
      timetouch2 = -1;
      timehold2 = -1;
    }
    if (timehold2 > 400) {
      if (ledStrip.isOn == true) {
        IncreaseBrightness();
        timetouch2 = -1;
        timehold2 = 0;
      }
    }
  } else {
    if (ledStrip.isOn == false){
      LEDOff();
    } else {
      LEDOn();
    }
  }
  last1 = touch1;
  last2 = touch2;
  delay(2);
}