#include <Arduino.h>
#include "../lib/displayseg.cpp"
#include "../include/config.h"

Display7Seg display(SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G, SEG_P, SRV2, SRV1, false);

int leds[] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8};
int num_leds = sizeof(leds) / sizeof(leds[0]);

void setup()
{
    display.begin();
    pinMode(LCD_E, OUTPUT);
    for (int i = 0; i < num_leds; i++)
    {
        pinMode(leds[i], OUTPUT);
    }
}

void loop()
{
    static int n = 0;
    display.showNumber(n);

    display.update();
    delay(5);

    // Incrementa número a cada 2 segundos
    static unsigned long lastChange = 0;
    if (millis() - lastChange > 300)
    {
        n++;
        if (n > 99)
        {
            n = 0;
            // desliga display
            digitalWrite(SRV1, LOW);
            digitalWrite(SRV2, LOW);
            // liga os leds
            digitalWrite(LCD_E, HIGH);
            for (int j = 0; j < 3; j++)
            {

                for (int i = 0; i < num_leds; i++)
                {
                    digitalWrite(leds[i], HIGH);
                }
                delay(500);
                for (int i = 0; i < num_leds; i++)
                {
                    digitalWrite(leds[i], LOW);
                }
                delay(500);
            }
        }
        digitalWrite(LCD_E, LOW);
        lastChange = millis();
    }
}
