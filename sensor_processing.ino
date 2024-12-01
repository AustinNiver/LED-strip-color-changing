void ProcessTouches(int touches,int sensorNum){

  switch (sensorNum) {

    case 1:
      switch (touches) {

        case 1:
          switch (ledStrip.isOn) {
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
              break;
            case false: // LED IS OFF AND WE TURN IT ON
              LEDOn();
              break;
          }
          break;

        case 2:
          if (ledStrip.isOn == true) { // LED ON SO WE START OR STOP BLINKING
            Blink();
          }
          break;

        case 3:
          if (ledStrip.isOn == true) { // LED ON SO WE TURN ON OR OFF RAINBOW
            Rainbow();
          }
          break;
      }
      break;
  }
}




