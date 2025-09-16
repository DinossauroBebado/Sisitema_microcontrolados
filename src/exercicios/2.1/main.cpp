
#include <Arduino.h>
#include "../include/config.h"

// Array com todos os LEDs
int leds[] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8};
int num_leds = sizeof(leds) / sizeof(leds[0]);

// Variável de contagem
uint8_t contador = 0;
void mostrarBinario(uint8_t valor);

void setup()
{
    pinMode(LCD_E, OUTPUT);
    digitalWrite(LCD_E, HIGH);
    // Configura todos os LEDs como saída
    for (int i = 0; i < num_leds; i++)
    {
        pinMode(leds[i], OUTPUT);
        digitalWrite(leds[i], LOW);
    }
    Serial.begin(9600);
}

void loop()
{
    // Atualiza LEDs conforme valor do contador
    mostrarBinario(contador);

    delay(300); // espera 300ms

    // Incrementa contador
    contador++;
    Serial.println(contador);
    // Se chegou no limite (255), reinicia
    if (contador == 255)
    {
        // Pisca todos os LEDs 3 vezes
        for (int i = 0; i < 4; i++)
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
        contador = 0; // reinicia
    }
}

// Função que mostra número binário nos LEDs
void mostrarBinario(uint8_t valor)
{
    for (int i = 0; i < num_leds; i++)
    {
        if (valor & (1 << i))
        {
            digitalWrite(leds[num_leds - 1 - i], HIGH);
        }
        else
        {
            digitalWrite(leds[num_leds - 1 - i], LOW);
        }
    }
}
