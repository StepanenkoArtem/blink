#include <Arduino.h>
// #include <avr/io.h>

void setPortMode(int, int);
void displayNumber(const int digit[8]);

#define ZERO {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW}
#define ONE {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW}
#define TWO {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH}
#define THREE {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH}
#define FOUR {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH}
#define FIVE {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH}
#define SIX {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH}
#define SEVEN {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW}
#define EIGHT {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}
#define NINE {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH}

const int DIGITS[10][8] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

const int PORT_D[] = {PD0, PD1, PD2, PD3, PD4, PD5, PD6, PD7};

void setup() { setPortMode(PORTD, OUTPUT); }

void loop() {
  int number = 0;

  while (number < 10) {
    displayNumber(DIGITS[number]);
    delay(1000);
    number++;
    if (number == 10) {
      number = 0;
    }
  };
}

void setPortMode(int port, int mode) {

  for (int pin = 0; pin <= 7; pin++) {
    pinMode(PORT_D[pin], mode);
  }
}

void displayNumber(const int digit[8]) {
  for (int pin = 0; pin <= 7; pin++) {
    digitalWrite(PORT_D[pin], !digit[pin]);
  }
};
