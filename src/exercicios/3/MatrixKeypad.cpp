#include "MatrixKeypad.h"

MatrixKeypad::MatrixKeypad(byte rowPins[4], byte colPins[4], unsigned long longPressDelay)
{
    for (byte i = 0; i < _numRows; i++)
    {
        _rowPins[i] = rowPins[i];
    }
    for (byte i = 0; i < _numCols; i++)
    {
        _colPins[i] = colPins[i];
    }

    _longPressDelay = longPressDelay;
    _confirmedState = "0000000000000000";

    // Inicializa o array de tempo com 0
    for (int i = 0; i < 16; i++)
    {
        _pressStartTime[i] = 0;
    }

    // Configura os pinos
    for (byte i = 0; i < _numRows; i++)
    {
        pinMode(_rowPins[i], OUTPUT);
        digitalWrite(_rowPins[i], HIGH);
    }
    for (byte i = 0; i < _numCols; i++)
    {
        pinMode(_colPins[i], INPUT_PULLUP);
    }
}

/**
 * @brief Realiza a varredura física do teclado.
 */
String MatrixKeypad::readHardware()
{
    String reading = "";
    reading.reserve(16);
    for (byte r = 0; r < _numRows; r++)
    {
        digitalWrite(_rowPins[r], LOW);
        for (byte c = 0; c < _numCols; c++)
        {
            reading += (digitalRead(_colPins[c]) == LOW) ? '1' : '0';
        }
        digitalWrite(_rowPins[r], HIGH);
    }
    return reading;
}

/**
 * @brief Lê o estado das teclas e confirma apenas os pressionamentos longos.
 */
String MatrixKeypad::readLongPressString()
{
    String currentState = readHardware();

    // Itera por cada uma das 16 teclas para gerenciar seu estado
    for (int i = 0; i < 16; i++)
    {
        bool isPressed = (currentState[i] == '1');

        if (isPressed)
        {
            // --- A TECLA ESTÁ SENDO PRESSIONADA ---

            if (_pressStartTime[i] == 0)
            {
                // Se o contador estava zerado, significa que a tecla ACABOU de ser pressionada.
                // Inicia a contagem de tempo.
                _pressStartTime[i] = millis();
            }
            else
            {
                // Se o contador já estava rodando, verifica se o tempo de long press foi atingido.
                if ((millis() - _pressStartTime[i]) > _longPressDelay)
                {
                    // Tempo atingido! Confirma o estado da tecla como '1'.
                    _confirmedState[i] = '1';
                }
            }
        }
        else
        {
            // --- A TECLA NÃO ESTÁ SENDO PRESSIONADA ---

            // Zera o contador de tempo e o estado confirmado para esta tecla.
            _pressStartTime[i] = 0;
            _confirmedState[i] = '0';
        }
    }

    return _confirmedState;
}