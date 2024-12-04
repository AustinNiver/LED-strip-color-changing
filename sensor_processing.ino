void ProcessTouches(int touches,int sensorNum){

  switch (sensorNum) {

    case 1:
      switch (touches) {

        case 1:
          switch (ledStrip.isOn) {
            ledStrip.isRainbow = false;
            ledStrip.isBlinking = false;
            case true:  // LED IS ON AND WE TURN IT OFF
              LEDOff();
              break;
            case false: // LED IS OFF AND WE TURN IT ON
              LEDOn();
              break;
          }
          break;

        case 2:
          if (ledStrip.isOn == true) { // LED ON SO WE CHANGE COLOR FORWARD
            ColorForward();
          }
          break;

        case 3:
          if (ledStrip.isOn == true) { // LED ON SO WE CHANGE COLOR BACK
            ColorBackward();
          }
          break;
      }
      break;


    case 2:
      switch (touches) {

        case 1:
          switch (ledStrip.isOn) {
            case true:  // LED IS ON AND WE TURN IT OFF
              LEDOff();
              ledStrip.isBlinking = false;
              ledStrip.isRainbow = false;
              break;
            case false: // LED IS OFF AND WE TURN IT ON
              LEDOn();
              break;
          }
          break;

        case 2:
          if (ledStrip.isOn == true) { // LED ON SO WE START OR STOP BLINKING
            if (ledStrip.isBlinking == false) {
              ledStrip.isBlinking = true;
              ledStrip.isRainbow = false;
              Blink();
            } else {
              ledStrip.isBlinking = false;
              LEDOn();
            }
            timer = 0;
          }
          break;

        case 3:
          if (ledStrip.isOn == true) { // LED ON SO WE TURN ON OR OFF RAINBOW
            if (ledStrip.isRainbow == false) {
              ledStrip.isRainbow = true;
              ledStrip.isBlinking = false;
              Rainbow();
            } else {
              ledStrip.isRainbow = false;
              rainbowNum = 0;
              LEDOn();
            }
            timer = 0;
          }
          break;
      }
      break;
  }
}




