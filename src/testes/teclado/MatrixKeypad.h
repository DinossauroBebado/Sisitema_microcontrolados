#ifndef MATRIXKEYPAD_H
#define MATRIXKEYPAD_H

#include <Arduino.h>

class MatrixKeypad
{
public:
    /**
     * @brief Construtor da classe MatrixKeypad.
     * @param rowPins Array com os 4 pinos das linhas.
     * @param colPins Array com os 4 pinos das colunas.
     * @param longPressDelay Tempo em ms para registrar um pressionamento longo.
     */
    MatrixKeypad(byte rowPins[4], byte colPins[4], unsigned long longPressDelay = 500);

    /**
     * @brief Lê o teclado e retorna o estado das teclas que foram pressionadas por mais tempo que o 'longPressDelay'.
     * @return String com 16 caracteres. '1' para uma tecla com pressionamento longo confirmado, '0' caso contrário.
     */
    String readLongPressString();

private:
    // Pinos
    byte _rowPins[4];
    byte _colPins[4];
    const byte _numRows = 4;
    const byte _numCols = 4;

    // Variáveis para detecção de Long Press
    unsigned long _longPressDelay;
    unsigned long _pressStartTime[16]; // Array para guardar o tempo de início de cada tecla
    String _confirmedState;            // Guarda o estado das teclas já confirmadas

    // Função interna para a leitura física
    String readHardware();
};

#endif