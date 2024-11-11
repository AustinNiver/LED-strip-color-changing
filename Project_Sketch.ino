#include <Adafruit_DotStar.h>
// Because conditional #includes don't work w/Arduino sketches...
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
//#include <avr/power.h> // ENABLE THIS LINE FOR GEMMA OR TRINKET


#define NUMPIXELS  72 // Number of LEDs in strip

// Here's how to control the LEDs from any two pins:
#define TOUCHDATAPIN 2  // Touch Sensor
#define DATAPIN    4    // Light Green Wire
#define CLOCKPIN   5    // Light Yellow Wire
#define SOUNDDATAPIN 7  // Sound Sensor
#define MAXBRIGHTNESS 150
#define LEASTBRIGHTNESS 20
Adafruit_DotStar strip(NUMPIXELS, DATAPIN, CLOCKPIN);
int currentState;
int lastState = LOW;
int ledState = LOW;
int ledColor = 4;
int touches = 0;
int timeAfterTouch = -1;
int lastBrightness = 10;
uint32_t lastColor = strip.Color(0,0,255);
uint32_t green = strip.Color(255,0,0);
uint32_t red = strip.Color(0,255,0);
uint32_t yellow = strip.Color(255,255,0);
uint32_t blue = strip.Color(0,0,255);
uint32_t cyan = strip.Color(255,0,255);
uint32_t magenta = strip.Color(0,255,255);
uint32_t white = strip.Color(255,255,255);


void setup() {
  pinMode(TOUCHDATAPIN,INPUT);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);
}

void loop(){
  
  currentState = digitalRead(TOUCHDATAPIN);
  switch (currentState) {
    case HIGH:
      switch (lastState) {
        case LOW:
          touches = touches + 1;
          timeAfterTouch = 0;
          break;
      }
    break;
  }
  if (timeAfterTouch > -1){
    timeAfterTouch = timeAfterTouch + 1;
  }
  if (timeAfterTouch > 1000){
    timeAfterTouch = 1000;
  }

  switch (timeAfterTouch) {
    case 1000:
      switch (touches) {
        case 3:
          switch (ledState) { // Somewhat Broken
            case LOW:
              strip.fill(lastColor,0,72);
              strip.setBrightness(lastBrightness);
              strip.show();
              ledState = HIGH;
              break;
            case HIGH:
              lastBrightness = strip.getBrightness();
              lastColor = strip.getPixelColor(1);
              strip.clear();
              strip.show();
              ledState = LOW;
              break;
          }
        case 2:
          switch (ledColor) {
            case 0:
              ledColor = 1;
              strip.fill(yellow,0,72);
              break;
            case 1:
              ledColor = 2;
              strip.fill(green,0,72);
              break;
            case 2:
              ledColor = 3;
              strip.fill(cyan,0,72);
              break;
            case 3:
              ledColor = 4;
              strip.fill(blue,0,72);
              break;
            case 4:
              ledColor = 5;
              strip.fill(magenta,0,72);
              break;
            case 5:
              ledColor = 6;
              strip.fill(white,0,72);
              break;
            case 6:
              ledColor = 0;
              strip.fill(red,0,72);
              break;
          }
        strip.setBrightness(lastBrightness);
        strip.show(); 
        break;
      }
      touches = -1;
      timeAfterTouch = -1;
      break;
  }
  delay(1);
  lastState = currentState;
}
  // sensorValue = digitalRead(SOUNDDATAPIN);
  // currentState = digitalRead(TOUCHDATAPIN);
  // uint32_t magenta = strip.Color(255, 0, 255);
  

  // // switch (sensorValue) {
  // //   case HIGH:
  // //     switch (lastSoundState) {
  // //       case LOW:
  // //         switch (ledState) {
  // //           case HIGH:
  // //             ledState = LOW;
  // //             break;
  // //           case LOW:
  // //             ledState = HIGH;
  // //             break;
  // //         }
  // //     break;
  // //     }
  // //   break;
  // // }

  // switch (ledState) {
  //   case HIGH:
  //     strip.rainbow(0,1,255,75,true);
  //     strip.show();
  //     break;
  //   case LOW:
  //     strip.clear();
  //     strip.show();
  //     break;
  // }
  // //strip.show();
  // lastState = currentState;
  // lastSoundState = sensorValue;
  // delay(1);

  // if(lastState == LOW && currentState == HIGH){
  //   // toggle LED state
  //   if(ledState == LOW)
  //     ledState = HIGH;
  //   else if(ledState == HIGH)
  //     ledState = LOW;
  // switch ledState{
  //   case HIGH:
  //     strip.show();
  //     break;
  //   case LOW:
  //     strip.clear();
  //     strip.show();
  //     break;
  // }
  // 