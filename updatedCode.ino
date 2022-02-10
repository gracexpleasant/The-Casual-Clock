
//states
#include "tinysnore.h"
int mode = -1;

//neopixels
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(12, 0, NEO_GRB + NEO_KHZ800);

//buttons
#include <Bounce2.h>
int buttonPins[4] = {1, 2, 3, 4};
Bounce * buttons = new Bounce[4];

// time
int curHours = 0;
int curMinutes = 0;
int curSeconds = 0;

long startTimer1;
long finishTimer;
int timerIndex = 0;
long startStopwatch;
int stopwatchIndex = 0;
int stopwatchCycle = 0;
int minuteButtonPress = 0;
int hourButtonPress = 0;


void setup() {
  initButtons();
  initNeopixels();
  startTimer1 = millis();
  startStopwatch = millis();
}

void loop() {
  updateButtons();
  updateTime();
}
