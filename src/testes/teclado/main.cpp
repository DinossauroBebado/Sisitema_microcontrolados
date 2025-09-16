
#include "MatrixKeypad.h"
#include "../include/config.h"

const byte ROWS = 4;
const byte COLS = 4;
byte rowPins[ROWS] = {KEY_R1, KEY_R2, KEY_R3, KEY_R4};
byte colPins[COLS] = {KEY_C1, KEY_C2, KEY_C3, KEY_C4};
// Crie uma instância da biblioteca, especificando o tempo de 500ms para o long press.
MatrixKeypad myKeypad(rowPins, colPins, 500);

String ultimoEstadoImpresso = "";

void setup()
{
    Serial.begin(115200);
    Serial.println("Leitor de Teclado - Deteccao de Long Press (500ms)");
    Serial.println("Pressione e segure uma tecla...");
}

void loop()
{
    // Lê o estado do teclado (apenas teclas com long press confirmado)
    String keypadState = myKeypad.readLongPressString();

    // Imprime o estado no monitor serial apenas se ele mudar
    // Isso demonstra claramente o efeito do long press.
    if (keypadState != ultimoEstadoImpresso)
    {
        Serial.print("Estado Confirmado: ");
        Serial.println(keypadState);
        ultimoEstadoImpresso = keypadState;
    }

    // Um pequeno delay para não sobrecarregar a CPU, mas o loop precisa rodar
    // rápido para que a detecção de tempo funcione bem.
    delay(10);
}