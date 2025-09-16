#ifndef MATRIXKEYPAD_H
#define MATRIXKEYPAD_H

#include <Arduino.h>

class MatrixKeypad
{
public:
    MatrixKeypad(byte rowPins[4], byte colPins[4]);
    String readBooleanString();

private:
    byte _rowPins[4];
    byte _colPins[4];
    const byte _numRows = 4;
    const byte _numCols = 4;
};

#endif