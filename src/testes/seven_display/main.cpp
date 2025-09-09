#include <Arduino.h>
#include "Display7Seg.h"

// Pinos do display
#define SEG_A 16
#define SEG_B 27
#define SEG_C 14
#define SEG_D 15
#define SEG_E 2
#define SEG_F 4
#define SEG_G 12
#define SEG_P 13

#define SRV1 18
#define SRV2 19

Display7Seg display(SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G, SEG_P, SRV1, SRV2, false);

void setup()
{
    display.begin();
}

void loop()
{
    static int n = 0;
    display.showNumber(n);

    // Atualiza multiplexação
    display.update();
    delay(5); // tempo pequeno para multiplexar

    // Incrementa número a cada 2 segundos
    static unsigned long lastChange = 0;
    if (millis() - lastChange > 2000)
    {
        n++;
        if (n > 99)
            n = 0;
        lastChange = millis();
    }
}
