// colors Defined in order below
uint32_t colors[7] = {strip.Color(0,0,255),strip.Color(255,0,255),strip.Color(255,0,0),strip.Color(255,255,0),strip.Color(0,255,0),strip.Color(0,255,255),strip.Color(255,255,255)};
#define BLUE    0
#define CYAN    1
#define GREEN   2
#define YELLOW  3
#define RED     4
#define MAGENTA 5
#define WHITE   6

// defining the minimum and maximum brightness values
#define MINBRIGHT 10
#define MAXBRIGHT 20


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
  ledStrip.isRainbow = false;
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
  ledStrip.isRainbow = false;
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
  ledStrip.brightness -= 5;
  if (ledStrip.brightness < MINBRIGHT) {
    ledStrip.brightness = MINBRIGHT;
  }
  strip.setBrightness(ledStrip.brightness);
  strip.show();
}

void IncreaseBrightness() {
  ledStrip.brightness += 5;
  if (ledStrip.brightness < MAXBRIGHT) {
    ledStrip.brightness = MAXBRIGHT;
  }
  strip.setBrightness(ledStrip.brightness);
  strip.show();
}

void Blink() {
  ledStrip.isRainbow = false;
  if (blinkOn = false) {
    blinkOn = true;
    strip.fill(colors[ledStrip.color],0,72);
    strip.setBrightness(ledStrip.brightness);
  } else {
    blinkOn = false;
    strip.clear();
  }
  strip.show();
}

void Rainbow() {
  if (ledStrip.color == 5){
    ledStrip.color = 0;
  } else {
    ledStrip.color += 1;
  }
  strip.fill(colors[ledStrip.color],0,72);
  strip.setBrightness(ledStrip.brightness);
  strip.show();
}