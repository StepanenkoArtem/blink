#include <Arduino.h>

void setPortAMode(int);
void displayNumber(int);

int const ONE[8] = {LOW, LOW, LOW, LOW, HIGH, HIGH, LOW, LOW};
// #define TWO {A, B, G, E, D}
// #define THREE {A, D, G, C, D}
// #define FOUR {F, G, B, C, D}
// #define FIVE {A, F, G, C, D}
// #define SIX {A, F, G, C, E, D}
// #define SEVEN {A, B, C}
// #define EIGHT {A, B, C, D, E, F, G, D}
// #define NINE {A, B, C, D, F, G, D}
// #define ZERO {}

void setup() { setPortAMode(OUTPUT); }

void loop() {
  int number = 1;

  while (number < 2) {
    displayNumber(number);
    delay(10000);
    // number++;
  }
}

// Other functions

void setPortAMode(int mode) {
  // int portAPins[] = {40, 39, 38, 37, 36, 35, 34, 33};

  for (int pin = 40; pin <= 33; pin--) {
    pinMode(pin, mode);
  }
};

void displayNumber(int number) {
  if (number == 1) {
    for (int pin = 0; pin <= 7; pin++) {
      digitalWrite((pin + 33), ONE[pin]);
    }
  }
};
