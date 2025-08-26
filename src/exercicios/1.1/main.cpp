#include <Arduino.h>
#include "../include/config.h"

// Array com todos os LEDs
int leds[] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8, LED_BUILTIN};
int num_leds = sizeof(leds) / sizeof(leds[0]);

void setup()
{

    pinMode(LCD_E, OUTPUT);
    digitalWrite(LCD_E, HIGH);
    // Configura todos os pinos como saída
    for (int i = 0; i < num_leds; i++)
    {
        pinMode(leds[i], OUTPUT);
        digitalWrite(leds[i], LOW); // Garante que todos comecem apagados
    }
}

void loop()
{
    // Acende todos
    for (int i = 0; i < num_leds; i++)
    {
        digitalWrite(leds[i], HIGH);
    }
    delay(100);
    for (int i = 0; i < num_leds; i++)
    {
        digitalWrite(leds[i], LOW);
    }
    delay(100);
}