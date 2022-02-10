
//NeoPixel stuff

void initNeopixels() {
  strip.begin();
  strip.clear();
  strip.show();
  strip.setBrightness(25);
}
