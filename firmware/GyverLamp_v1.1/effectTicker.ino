uint32_t effTimer;

void effectsTick() {
  if (!dawnFlag) {
    if (ONflag && millis() - effTimer >= ((currentMode < 5) ? modes[currentMode].speed : 50) ) {
      effTimer = millis();
      switch (currentMode) {
        case 0: sparklesRoutine();
          break;
        case 1: fireRoutine();
          break;
        case 2: rainbowVertical();
          break;
        case 3: rainbowHorizontal();
          break;
        case 4: colorsRoutine();
          break;
        case 5: madnessNoise();
          break;
        case 6: cloudNoise();
          break;
        case 7: lavaNoise();
          break;
        case 8: plasmaNoise();
          break;
        case 9: rainbowNoise();
          break;
        case 10: rainbowStripeNoise();
          break;
        case 11: zebraNoise();
          break;
        case 12: forestNoise();
          break;
        case 13: oceanNoise();
          break;
      }
      FastLED.show();
    }
  }
}

void changePower() {
  if (ONflag) {
    effectsTick();
    for (int i = 0; i < modes[currentMode].brightness; i += 8) {
      FastLED.setBrightness(i);
      delay(1);
      FastLED.show();
    }
    FastLED.setBrightness(modes[currentMode].brightness);
    FastLED.show();
  } else {
    effectsTick();
    for (int i = modes[currentMode].brightness; i > 8; i -= 8) {
      FastLED.setBrightness(i);
      delay(1);
      FastLED.show();
    }
    FastLED.clear();
    FastLED.show();
  }
}
