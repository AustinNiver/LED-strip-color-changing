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
#define MAXBRIGHT 100
int rainbowNum = 0;


void LEDOn() {
  ledStrip.isOn = true;
  strip.fill(colors[ledStrip.color],0,72);
  strip.setBrightness(ledStrip.brightness);
  strip.show();
  Serial.println("Turn on LED");
}

void LEDOff() {
  ledStrip.isOn = false;
  strip.clear();
  strip.show();
  Serial.println("Turn off LED");
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
  Serial.println("Change Color of LED Forward");
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
  Serial.println("Change Color of LED Backward");
}

void DecreaseBrightness() {
  ledStrip.brightness -= 5;
  uint32_t currentColor = strip.getPixelColor(0);
  if (ledStrip.brightness < MINBRIGHT) {
    ledStrip.brightness = MINBRIGHT;
  }
  strip.setBrightness(ledStrip.brightness);
  strip.fill(currentColor,0,72);
  strip.show();
  Serial.println("Decreasing Brightness");
}

void IncreaseBrightness() {
  ledStrip.brightness += 5;
  uint32_t currentColor = strip.getPixelColor(0);
  if (ledStrip.brightness > MAXBRIGHT) {
    ledStrip.brightness = MAXBRIGHT;
  }
  strip.setBrightness(ledStrip.brightness);
  strip.fill(currentColor,0,72);
  strip.show();
  Serial.println("Increasing Brightness");
}

void Blink() {
  if (blinkOn == false) {
    blinkOn = true;
    strip.fill(colors[ledStrip.color],0,72);
    strip.setBrightness(ledStrip.brightness);
  } else {
    blinkOn = false;
    strip.clear();
  }
  strip.show();
  Serial.println("Blink mode On");
}

void Rainbow() {
  if (rainbowNum == 5){
    rainbowNum = 0;
  } else {
    rainbowNum += 1;
  }
  strip.fill(colors[rainbowNum],0,72);
  strip.setBrightness(ledStrip.brightness);
  strip.show();
  Serial.println("Rainbow mode On");
}