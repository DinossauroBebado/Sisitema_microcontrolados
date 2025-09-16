#include <Arduino.h>
#include <LiquidCrystal.h>
#include "MatrixKeypad.h" // Inclui a biblioteca do teclado
#include "../include/config.h"

// ===================================================================================
// 1. CONFIGURAÇÃO DOS PERIFÉRICOS (LEDs, LCD, TECLADO)
// ===================================================================================

// --- LEDs ---
int leds[] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8, LED_BUILTIN};
int num_leds = sizeof(leds) / sizeof(leds[0]);

// --- LCD ---
LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

// --- Teclado Matricial ---
const byte ROWS = 4;
const byte COLS = 4;
byte rowPins[ROWS] = {KEY_R1, KEY_R2, KEY_R3, KEY_R4};
byte colPins[COLS] = {KEY_C1, KEY_C2, KEY_C3, KEY_C4};
MatrixKeypad myKeypad(rowPins, colPins, 500); // Usando a versão com debounce de 50ms

// ===================================================================================
// 2. VARIÁVEIS DE CONTROLE DO PROGRAMA
// ===================================================================================

// --- Controle do Pisca-pisca (Blink Without Delay) ---
unsigned long previousMillis = 0;
int blinkInterval = 700; // Intervalo inicial de 700 ms
bool ledState = LOW;

// --- Controle de estado do Teclado ---
// Guarda o último estado para detectar apenas uma vez o pressionar da tecla
String lastKeypadState = "0000000000000000";

// ===================================================================================
// 3. FUNÇÕES AUXILIARES
// ===================================================================================

// Função para exibir as mensagens iniciais no LCD
void displayInitialMessage()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("UTFPR");
    lcd.setCursor(0, 1);
    lcd.print("Guilherme 25"); // <-- ALTERE PARA SEU NOME E IDADE
}

// Função para atualizar o estado de todos os LEDs
void setAllLeds(bool state)
{
    for (int i = 0; i < num_leds; i++)
    {
        digitalWrite(leds[i], state);
    }
}

// ===================================================================================
// 4. FUNÇÃO SETUP
// ===================================================================================
void setup()
{
    Serial.begin(115200);

    // --- Inicializa os LEDs ---
    for (int i = 0; i < num_leds; i++)
    {
        pinMode(leds[i], OUTPUT);
    }

    // --- Inicializa o LCD ---
    lcd.begin(16, 2);
    displayInitialMessage(); // Mostra a mensagem inicial
}

// ===================================================================================
// 5. FUNÇÃO LOOP
// ===================================================================================
void loop()
{

    // --- Tarefa 2: Ler o Teclado e Atualizar o Display ---
    String keypadState = myKeypad.readLongPressString();

    // Processa a tecla apenas na mudança de estado (quando uma tecla é pressionada)
    if (keypadState != lastKeypadState && keypadState != "0000000000000000")
    {

        // Tecla '1' pressionada (primeiro caractere da string)
        if (keypadState[3] == '1') // A
        {
            Serial.println("Tecla  Pressionada");
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Eng. Mecatronica"); // <-- ALTERE PARA SEU CURSO
            delay(100);
            digitalWrite(LCD_E, HIGH);
            digitalWrite(LCD_E, LOW);
            setAllLeds(HIGH);
            delay(300);
            setAllLeds(LOW);
            digitalWrite(LCD_E, HIGH);
            digitalWrite(LCD_E, LOW);
            // digitalWrite(LCD_E, LOW);
            // lcd.print("Eng. Mecatronica");
            delay(100);
        }
        // Tecla '2' pressionada (segundo caractere da string)
        else if (keypadState[11] == '1') // C
        {
            Serial.println("Tecla 2 Pressionada");
            lcd.clear();
            lcd.setCursor(0, 1);
            lcd.print("Microcontroladores");
            delay(100);
            digitalWrite(LCD_E, HIGH);
            digitalWrite(LCD_E, LOW);
            setAllLeds(HIGH);
            delay(300);
            setAllLeds(LOW);
            digitalWrite(LCD_E, HIGH);
            digitalWrite(LCD_E, LOW);
            // digitalWrite(LCD_E, LOW);
            // lcd.print("Microcontroladores");

            delay(100);
        }
        // Tecla '3' pressionada (terceiro caractere da string)
        else if (keypadState[15] == '1') // D
        {
            Serial.println("Tecla 3 Pressionada");
            displayInitialMessage(); // Volta para a mensagem inicial
            delay(100);
            digitalWrite(LCD_E, HIGH);
            digitalWrite(LCD_E, LOW);
            setAllLeds(HIGH);
            delay(300);
            setAllLeds(LOW); // Volta para o intervalo inicial
            // digitalWrite(LCD_E, LOW);
            digitalWrite(LCD_E, HIGH);
            digitalWrite(LCD_E, LOW);
            delay(100);
        }
    }

    // Atualiza o último estado do teclado para a próxima iteração
    lastKeypadState = keypadState;
    digitalWrite(LCD_E, LOW);
}