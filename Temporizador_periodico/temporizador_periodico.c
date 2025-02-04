/*
    Tarefa 1 - Aula sincrona 29/01 - Unidade 4 - Microcontroladores
    Projeto de semáforo utilizado o temporizador periodico
    Atenilton Santos de Souza Júnior
 */

// Bibliotecas
#include <stdio.h>
#include "pico/stdlib.h"     // Inclui a biblioteca padrão para funcionalidades básicas como GPIO, temporização e comunicação serial.
#include "hardware/timer.h" // Inclui a biblioteca para gerenciamento de temporizadores de hardware.

#define green 11    // Definindo o led verde no pino 11 (vermelho da bitDogLab)
#define yellow 12  // Definindo o led amarelo no pino 12 (azul da bitDogLab)
#define red 13    //Definindo o led vermelho no pino 13 (Verde da BitDogLab)

int estado_atual = 1;      // Definindo o estado atual igual ao case 1
int estado_semaforo = 1;  // Estado da mensagem exibida no semaf
int tempo_led = 3000;    // Intervalo de 3 segundos
int tempo_print = 1000; // Intervalo de 1 segundo

// Inicializando leds
void iniciar() {
  gpio_init(red); gpio_set_dir(red, GPIO_OUT);         //led vermelho
  gpio_init(green); gpio_set_dir(green, GPIO_OUT);    // led verde
  gpio_init(yellow); gpio_set_dir(yellow, GPIO_OUT); // led amarelo
}

// Função para ligar os leds com uma linha de código
void state(bool r, bool y, bool g) {
  gpio_put(red, r);
  gpio_put(green, g);
  gpio_put(yellow, y);
}

/* Função de callback que será chamada repetidamente pelo temporizador
 O tipo bool indica que a função deve retornar verdadeiro ou falso para continuar ou parar o temporizador. */
void verifica_estado() {
  switch(estado_atual) {
    case 1:
        state(0, 0, 1); // verde
        break;
    case 2:
        state(0, 1, 0); // amarelo
        break;
    case 3:
        state(1, 0, 0); // vermelho
        break;
  }}

// Função para imprimir o estado do semáforo
void temp_semaforo() {
  switch(estado_semaforo) {
    case 1:
        printf("🔴 3 🔴\n");
        break;
    case 2:
        printf("🔴 2 🔴\n");
        break;
    case 3:
        printf("🔴 1 🔴\n");
        break;
    case 4:
        printf("🟡 3 🟡\n");
        break;
    case 5:
        printf("🟡 2 🟡\n");
        break;
    case 6:
        printf("🟡 1 🟡\n");
        break;
    case 7:
        printf("🟢 3 🟢\n");
        break;
    case 8:
        printf("🟢 2 🟢\n");
        break;
    case 9:
        printf("🟢 1 🟢\n");
        break;
  }
}

// Função de callback para o timer que alterna os LEDs
bool repeating_timer_callback_leds(struct repeating_timer *t) {
    estado_atual++;
    if(estado_atual > 3) {
      estado_atual = 1;
    }
    verifica_estado();
    return true; // Retorna true para continuar o temporizador.
}

// Função de callback para o timer que exibe a mensagem
bool repeating_timer_callback_mensagens(struct repeating_timer *t) {
    estado_semaforo++;
    if(estado_semaforo > 9) {
        estado_semaforo = 1;
    }
    temp_semaforo();
    return true; // Retorna true para continuar o temporizador.
}

int main() {
    iniciar();           // Habilitar os pinos dos leds na principal
    stdio_init_all();   // Habilita o monitor serial
    verifica_estado(); // Switch dos leds
    temp_semaforo();  //Switch das mensagens periodicas

    struct repeating_timer timer_leds;
    struct repeating_timer timer_mensagens;

    // Configura o temporizador para alternar os LEDs a cada 3 segundos
    add_repeating_timer_ms(tempo_led, repeating_timer_callback_leds, NULL, &timer_leds);

    // Configura o temporizador para exibir a mensagem a cada 1 segundo
    add_repeating_timer_ms(tempo_print, repeating_timer_callback_mensagens, NULL, &timer_mensagens);

    // Importe que os dois temporizadores estejam sincronizados com duração de 9 segundos cada

    // Loop infinito que mantém o programa em execução.
    while (1) {
        // O loop infinito apenas mantém o programa em execução, os timers já estão fazendo o trabalho
    }
    return 0;
}