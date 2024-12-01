// colors Defined in order below
uint32_t colors[7] = {strip.Color(0,0,255),strip.Color(255,0,255),strip.Color(255,0,0),strip.Color(255,255,0),strip.Color(0,255,0),strip.Color(0,255,255),strip.Color(255,255,255)};
#define BLUE    0
#define CYAN    1
#define GREEN   2
#define YELLOW  3
#define RED     4
#define MAGENTA 5
#define WHITE   6


void LEDOn() {
  ledStrip.isOn = true;
  strip.fill(colors[ledStrip.color],0,72);
  strip.setBrightness(ledStrip.brightness);
  strip.show();
}

void LEDOff() {
  ledStrip.isOn = false;
  strip.clear();
  strip.show();
}

void ColorForward() {
  if (ledStrip.color == 6){
    ledStrip.color = 0;
  } else {
    ledStrip.color += 1;
  }
  strip.fill(colors[ledStrip.color],0,72);
  strip.setBrightness(ledStrip.brightness);
  strip.show();
}

void ColorBackward() {
  if (ledStrip.color == 0){
    ledStrip.color = 6;
  } else {
    ledStrip.color -= 1;
  }
  strip.fill(colors[ledStrip.color],0,72);
  strip.setBrightness(ledStrip.brightness);
  strip.show();
}

void DecreaseBrightness() {
  
}

void IncreaseBrightness() {

}

void Blink() {

}

void Rainbow() {

}