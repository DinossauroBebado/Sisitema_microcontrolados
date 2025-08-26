#include <Arduino.h>
#include "../include/config.h"

// Array com os segmentos (ordem A-G + P)
int segmentos[] = {SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G, SEG_P};
int num_segmentos = sizeof(segmentos) / sizeof(segmentos[0]);

// Tabela para números de 0 a 9
// Ordem dos bits: A B C D E F G P
// 1 = segmento aceso, 0 = apagado
byte digitos[10] = {
    // A B C D E F G P
    B11111100, // 0
    B01100000, // 1
    B11011010, // 2
    B11110010, // 3
    B01100110, // 4
    B10110110, // 5
    B10111110, // 6
    B11100000, // 7
    B11111110, // 8
    B11110110  // 9
};

// Função que mostra um número no display
void mostrarNumero(int n)
{
    byte valor = digitos[n];
    for (int i = 0; i < 8; i++)
    {
        bool ligado = valor & (1 << (7 - i));
        digitalWrite(segmentos[i], ligado ? HIGH : LOW);
    }
}
void setup()
{

    pinMode(SRV1, OUTPUT);
    digitalWrite(SRV1, HIGH);
    pinMode(SRV2, OUTPUT);
    digitalWrite(SRV2, HIGH);
    // Configura todos os segmentos como saída
    for (int i = 0; i < num_segmentos; i++)
    {
        pinMode(segmentos[i], OUTPUT);
        digitalWrite(segmentos[i], LOW); // começa desligado
    }
}

void loop()
{
    // Conta de 0 até 9
    for (int num = 0; num < 10; num++)
    {
        mostrarNumero(num);
        delay(1000); // espera 1 segundo entre os números
    }
}
