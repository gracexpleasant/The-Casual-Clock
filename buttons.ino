void initButtons() {
  for (int i = 0; i < 4; i++) {
    buttons[i].attach(buttonPins[i], INPUT);
    buttons[i].interval(25);
  }
}

void updateButtons() {
  switch (mode) {
    case -1:
      fallAsleep();
      for (int i = 0; i < 4; i++)  {
        buttons[i].update();
        if (buttons[i].rose()) {
          mode = i;
        }
      }
      break;
    case 0:
      strip.clear();
      displayTime();
      buttons[1].update();
      if (buttons[1].rose()) {
        minuteButtonPress ++;
        strip.show();
      }
      buttons[2].update();
      if (buttons[2].rose()) {
        hourButtonPress ++;
      }
      buttons[3].update();
      if (buttons[3].rose()) {
        mode = -1;
      }
      break;
    case 1:
      //strip.clear();
      startTimer();
      buttons[0].update();
      if (buttons[0].rose()) {
        strip.clear();
        timerIndex = 0;
      }
      buttons[3].update();
      if (buttons[3].rose()) {
        mode = -1;
      }
      break;
    case 2:
      strip.clear();
      flashlight();
      buttons[0].update();
      if (buttons[0].rose()) {
      }
      buttons[3].update();
      if (buttons[3].rose()) {
        mode = -1;
      }
      break;
  }
}
