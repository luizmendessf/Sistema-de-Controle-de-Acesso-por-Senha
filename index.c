/*
 * Projeto: Sistema de Controle de Acesso por Senha
 * Autor: Luiz Mendes
 * Descrição:
 *   Este código implementa um sistema de controle de acesso usando um teclado matricial.
 *   O usuário pode definir uma senha e utilizá-la para abrir a porta.
 *   Caso a senha seja digitada incorretamente, um contador de tentativas é incrementado.
 *   O sistema utiliza um display LCD para fornecer feedback visual ao usuário.
 *   O botão conectado ao PORTC.b7 permite fechar a porta manualmente.
 */

 #include <stdio.h>

 // Variáveis globais para armazenamento da senha e tentativas
 int zeracnt1 = 0; // Variável de controle para resetar contadores
 int definirsenha = 1; // Flag para definir se a senha está sendo configurada
 unsigned int kp, cnt1 = 0; // kp armazena a tecla pressionada, cnt1 conta os dígitos inseridos
 int s1 = 0, s2 = 0, s3 = 0, s4 = 0; // Armazena a senha definida pelo usuário
 int tent1 = 0, tent2 = 0, tent3 = 0, tent4 = 0, cnttent = 0; // Variáveis para tentativas de senha
 char txt[6];
 int porta_aberta = 0; // Estado da porta (0 = fechada, 1 = aberta)
 
 #define botao_fechar PORTC.b7 // Definição do botão de fechamento da porta
 
 // Conexões do teclado matricial
 char keypadPort at PORTD;
 
 // Conexões do módulo LCD
 sbit LCD_RS at RB4_bit;
 sbit LCD_EN at RB5_bit;
 sbit LCD_D4 at RB0_bit;
 sbit LCD_D5 at RB1_bit;
 sbit LCD_D6 at RB2_bit;
 sbit LCD_D7 at RB3_bit;
 
 sbit LCD_RS_Direction at TRISB4_bit;
 sbit LCD_EN_Direction at TRISB5_bit;
 sbit LCD_D4_Direction at TRISB0_bit;
 sbit LCD_D5_Direction at TRISB1_bit;
 sbit LCD_D6_Direction at TRISB2_bit;
 sbit LCD_D7_Direction at TRISB3_bit;
 
 void main() {
     cnt1 = 0;  // Zera o contador de dígitos
     Keypad_Init();  // Inicializa o teclado matricial
     ANSEL = 0;  // Configura pinos analógicos como I/O digital
     ANSELH = 0;
     TRISC7_bit = 1;
     PORTC = 0;  // Inicializa o botão de fechamento da porta
     Lcd_Init();  // Inicializa o display LCD
     Lcd_Cmd(_LCD_CLEAR); // Limpa o display
     Lcd_Cmd(_LCD_CURSOR_OFF); // Desativa o cursor
 
     while (1) {
         // Processo de definição da senha
         while (definirsenha == 1) {
             Lcd_Out(1, 1, "Defina a senha:");
             kp = 0;
             while (!kp) {
                 kp = Keypad_Key_Click(); // Espera pelo pressionamento de uma tecla
             }
 
             // Converte a tecla pressionada para seu respectivo valor ASCII
             switch (kp) {
                 case 1: kp = '1'; break;
                 case 2: kp = '2'; break;
                 case 3: kp = '3'; break;
                 case 4: kp = 'A'; break;
                 case 5: kp = '4'; break;
                 case 6: kp = '5'; break;
                 case 7: kp = '6'; break;
                 case 8: kp = 'B'; break;
                 case 9: kp = '7'; break;
                 case 10: kp = '8'; break;
                 case 11: kp = '9'; break;
                 case 12: kp = 'C'; break;
                 case 13: kp = '*'; break;
                 case 14: kp = '0'; break;
                 case 15: kp = '#'; break;
                 case 16: kp = 'D'; break;
             }
 
             if (kp != 0) cnt1++;
 
             // Armazena os valores digitados na senha
             if (cnt1 == 1) s1 = kp;
             else if (cnt1 == 2) s2 = kp;
             else if (cnt1 == 3) s3 = kp;
             else if (cnt1 == 4) {
                 s4 = kp;
                 Lcd_Out(1, 1, "Senha definida.");
                 delay_ms(4000);
                 definirsenha = 0;
                 zeracnt1 = 1;
                 Lcd_Cmd(_LCD_CLEAR);
             }
         }
 
         // Processo de inserção e verificação da senha
         while (definirsenha == 0) {
             Lcd_Out(1, 1, "Insira senha");
             if (zeracnt1 == 1) {
                 cnt1 = 0;
                 zeracnt1 = 0;
             }
 
             kp = 0;
             while (!kp) {
                 kp = Keypad_Key_Click();
             }
 
             if (kp != 0) cnt1++;
             if (cnt1 == 1) tent1 = kp;
             else if (cnt1 == 2) tent2 = kp;
             else if (cnt1 == 3) tent3 = kp;
             else if (cnt1 == 4) {
                 tent4 = kp;
                 delay_ms(1000);
                 
                 // Verifica se a senha inserida está correta
                 if (tent1 == s1 && tent2 == s2 && tent3 == s3 && tent4 == s4) {
                     Lcd_Cmd(_LCD_CLEAR);
                     Lcd_Out(1, 1, "Senha correta!");
                     Lcd_Out(2, 1, "Porta aberta.");
                     zeracnt1 = 1;
                     cnttent = 0;
                     delay_ms(5000);
                     porta_aberta = 1;
                 } else {
                     Lcd_Cmd(_LCD_CLEAR);
                     Lcd_Out(1, 1, "Senha incorreta.");
                     cnttent++;
                     Lcd_Chr(2, 9, cnttent);
                     Lcd_Out(2, 12, "tent.");
                     delay_ms(5000);
                     Lcd_Cmd(_LCD_CLEAR);
                 }
             }
         }
     }
 }
 