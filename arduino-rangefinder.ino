#include "Ultrasonic.h"

#define LED_PIN BUILTIN_LED
#define TRIG_PIN D6
#define ECHO_PIN D7
#define DISTANCE 50.00
#define TIMEOUT 3000

Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN);

void setup()
{
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
}

void loop()
{
  float dist_cm = ultrasonic.Ranging(CM);

  Serial.print(dist_cm);
  Serial.println(" cm");

  dist_cm <= DISTANCE ? light() : night();

  delay(100);
}

void light()
{
  digitalWrite(LED_PIN, LOW);
  delay(TIMEOUT);
}

void night()
{
  digitalWrite(LED_PIN, HIGH);
}
