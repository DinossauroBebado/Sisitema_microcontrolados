#ifndef DISPLAY7SEG_H
#define DISPLAY7SEG_H

#include <Arduino.h>

// Classe para controle de display de 7 segmentos com 2 dígitos
class Display7Seg
{
public:
    Display7Seg(int segA, int segB, int segC, int segD,
                int segE, int segF, int segG, int segP,
                int sr1, int sr2, bool anodoComum = false);

    void begin();
    void showNumber(int number); // mostra número de 0 a 99
    void update();               // deve ser chamado no loop para multiplexar

private:
    int _segments[8];  // pinos dos segmentos
    int _sr1, _sr2;    // pinos dos transistores
    bool _anodoComum;  // tipo de display
    int _currentDigit; // dígito ativo (0 ou 1)
    int _number;       // número a ser mostrado
    byte _digits[10];  // tabela de segmentos

    void setDigit(int digit, int value);
};

#endif
