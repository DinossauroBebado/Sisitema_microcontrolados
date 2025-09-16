// Inclui a biblioteca padrão para displays de cristal líquido
#include <LiquidCrystal.h>
#include "../include/config.h"
#include <Arduino.h>
// ===================================================================================
// CONFIGURAÇÃO DOS PINOS
// Mapeie aqui os pinos do ESP32 que você conectou ao LCD.
// Se você usou pinos diferentes do esquemático, altere-os aqui.
// ===================================================================================
const int rs = LCD_RS;
const int en = LCD_E;
const int d4 = LCD_D4;
const int d5 = LCD_D5;
const int d6 = LCD_D6;
const int d7 = LCD_D7;

// Inicializa o objeto da biblioteca com os pinos que você definiu
// Sintaxe: LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Variável para o contador de exemplo
unsigned long contador = 0;

// ===================================================================================
// FUNÇÃO SETUP: Executa uma vez quando o ESP32 é ligado ou resetado
// ===================================================================================
void setup()
{
    // Inicializa o display com 16 colunas e 2 linhas
    lcd.begin(16, 2);

    // Limpa qualquer texto que possa ter ficado no display
    lcd.clear();

    // Posiciona o cursor na coluna 3, linha 0 (primeira linha)
    lcd.setCursor(3, 0);
    // Escreve o texto
    lcd.print("ESP32 com");

    // Posiciona o cursor na coluna 1, linha 1 (segunda linha)
    lcd.setCursor(1, 1);
    lcd.print("LCD Paralelo!");

    // Aguarda 3 segundos para a mensagem de boas-vindas ser lida
    delay(3000);
}

// ===================================================================================
// FUNÇÃO LOOP: Executa continuamente após o setup
// ===================================================================================
void loop()
{
    // Limpa a tela
    lcd.clear();

    // Posiciona o cursor na primeira linha
    lcd.setCursor(0, 0);
    lcd.print("Tempo ativo:");

    // Posiciona o cursor na segunda linha para mostrar o contador
    lcd.setCursor(0, 1);
    lcd.print(contador);
    lcd.print(" segundos");

    // Incrementa o contador
    contador++;

    // Aguarda 1 segundo
    delay(1000);
}