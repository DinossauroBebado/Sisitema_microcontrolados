#include "Display7Seg.h"

Display7Seg::Display7Seg(int segA, int segB, int segC, int segD,
                         int segE, int segF, int segG, int segP,
                         int sr1, int sr2, bool anodoComum)
{
    _segments[0] = segA;
    _segments[1] = segB;
    _segments[2] = segC;
    _segments[3] = segD;
    _segments[4] = segE;
    _segments[5] = segF;
    _segments[6] = segG;
    _segments[7] = segP;

    _sr1 = sr1;
    _sr2 = sr2;
    _anodoComum = anodoComum;
    _currentDigit = 0;
    _number = 0;

    // Tabela para números 0-9 (A B C D E F G P)
    byte tempDigits[10] = {
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
    memcpy(_digits, tempDigits, sizeof(_digits));
}

void Display7Seg::begin()
{
    for (int i = 0; i < 8; i++)
    {
        pinMode(_segments[i], OUTPUT);
        digitalWrite(_segments[i], _anodoComum ? HIGH : LOW);
    }
    pinMode(_sr1, OUTPUT);
    pinMode(_sr2, OUTPUT);
    digitalWrite(_sr1, LOW);
    digitalWrite(_sr2, LOW);
}

void Display7Seg::showNumber(int number)
{
    if (number < 0)
        number = 0;
    if (number > 99)
        number = 99;
    _number = number;
}

void Display7Seg::update()
{
    int dezenas = _number / 10;
    int unidades = _number % 10;

    // Desliga ambos antes de trocar
    digitalWrite(_sr1, LOW);
    digitalWrite(_sr2, LOW);

    if (_currentDigit == 0)
    {
        setDigit(0, unidades);
        digitalWrite(_sr1, HIGH); // ativa primeiro dígito
    }
    else
    {
        setDigit(1, dezenas);
        digitalWrite(_sr2, HIGH); // ativa segundo dígito
    }

    _currentDigit = 1 - _currentDigit; // alterna dígito
}

void Display7Seg::setDigit(int digit, int value)
{
    byte val = _digits[value];
    for (int i = 0; i < 8; i++)
    {
        bool ligado = val & (1 << (7 - i));
        if (_anodoComum)
            digitalWrite(_segments[i], ligado ? LOW : HIGH);
        else
            digitalWrite(_segments[i], ligado ? HIGH : LOW);
    }
}
