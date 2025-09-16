#include "MatrixKeypad.h"

/**
 * @brief Construtor da classe MatrixKeypad.
 * * @param rowPins Array com os 4 pinos das linhas.
 * @param colPins Array com os 4 pinos das colunas.
 */
MatrixKeypad::MatrixKeypad(byte rowPins[4], byte colPins[4])
{
    for (byte i = 0; i < _numRows; i++)
    {
        _rowPins[i] = rowPins[i];
    }
    for (byte i = 0; i < _numCols; i++)
    {
        _colPins[i] = colPins[i];
    }

    // Configura os pinos das linhas como saída
    for (byte i = 0; i < _numRows; i++)
    {
        pinMode(_rowPins[i], OUTPUT);
        digitalWrite(_rowPins[i], HIGH); // Garante que as linhas comecem em estado alto
    }

    // Configura os pinos das colunas como entrada com pull-up interno
    for (byte i = 0; i < _numCols; i++)
    {
        pinMode(_colPins[i], INPUT_PULLUP);
    }
}

/**
 * @brief Lê o estado de todas as teclas do teclado matricial.
 * * @return String com 16 caracteres ('0' ou '1') representando o estado de cada tecla.
 * A ordem das teclas é da esquerda para a direita, de cima para baixo.
 */
String MatrixKeypad::readBooleanString()
{
    String boolString = "";
    boolString.reserve(16); // Pre-aloca memória para a string

    for (byte r = 0; r < _numRows; r++)
    {
        // Ativa uma linha de cada vez, colocando-a em LOW
        digitalWrite(_rowPins[r], LOW);

        for (byte c = 0; c < _numCols; c++)
        {
            // Lê o estado da coluna. Se estiver LOW, a tecla está pressionada
            if (digitalRead(_colPins[c]) == LOW)
            {
                boolString += '1';
            }
            else
            {
                boolString += '0';
            }
        }

        // Desativa a linha, retornando-a para HIGH
        digitalWrite(_rowPins[r], HIGH);
    }

    return boolString;
}