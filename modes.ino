// Modes

long sleepTimer = 0;
long sleepInterval = 5000;
int fasterTime = 100;

void fallAsleep() {
  if (millis() - sleepTimer > sleepInterval) {
    strip.clear(); strip.show();  // Clear out NeoPixel Display
    snore(5000);                 // Go to Sleep for 5 Seconds
    sleepTimer = millis();
  }
}

//----------------------------------------------------------

void updateTime() {
  curSeconds = millis() / (1000 / fasterTime);
  curMinutes = ((millis() / (60000 / fasterTime)) + (minuteButtonPress * 5)) % 60;
  curHours = ((millis() / (3600000 / fasterTime)) + hourButtonPress) % 12;
}

void displayTime() {
  strip.clear();
  int minLed = map(curMinutes, 0, 55, 11, 0);
  strip.setPixelColor(minLed, 31, 86, 115);
  int hoursLed = map (curHours, 0, 11, 11, 0);
  strip.setPixelColor(hoursLed, 248, 117, 117);
  strip.show();
}

//----------------------------------------------------------

//function 1: timer
//30 second timer that turns on a neopixel every 2.5 seconds

long timerInterval = 1000;
uint32_t timerColor = strip.Color (0, 255, 255);


void startTimer() {
  if (millis() - startTimer1 > timerInterval) {
    strip.setPixelColor(timerIndex, timerColor);
    timerIndex += 1;
    strip.show();
    startTimer1 = millis();
  }
  if (timerIndex == 12) {
    mode = -1;
  }

}

//----------------------------------------------------------

//function 2: stopwatch

long stopwatchInterval = 200;
uint32_t stopwatchColor = strip.Color(255, 0, 255);

void stopwatch() {
  if (millis() - startStopwatch >= stopwatchInterval) {
    strip.setPixelColor(stopwatchIndex, stopwatchColor);
    strip.setPixelColor(stopwatchIndex - 1, 0, 0, 0);
    stopwatchIndex = stopwatchIndex + 1;
    strip.show();
    if (stopwatchIndex >= strip.numPixels()) {
      strip.setPixelColor(stopwatchIndex - 1, 0, 0, 0);
      stopwatchIndex = 0;
    }
    startStopwatch = millis();
    stopwatchCycle += 1;
  }
  if (stopwatchCycle >= 36) {
    mode = -1;
  }
}


//----------------------------------------------------------

//function 3: flashlight

uint32_t flashlightColor = strip.Color(255, 255, 255);
void flashlight() {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setBrightness(20);
    strip.setPixelColor(i, flashlightColor);
    strip.show();
  }
}

//----------------------------------------------------------
