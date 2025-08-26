#include <Arduino.h>
#include "../include/config.h"

void setup()
{
    pinMode(POT, INPUT);
    Serial.begin(9600);
}

void loop()
{
    Serial.println(analogRead(POT));
}