# 💡 Tarefa: Clock e Temporizadores 🕰️
Atividade Avaliativa Individual
Proposta pelo Cepedi como parte dos critérios de avaliação do curso de capacitação em Software e Sistemas Embarcados — Embarcatech.

Tarefa 1: Aula síncrona (29/01) — Unidade 4: Microcontroladores
Projeto: Desenvolvimento de um sistema de semáforo utilizando temporizador periódico

Discente: Atenilton Santos de Souza Júnior
    
## Sumário 📑
- [Descrição Geral](#descri%C3%A7%C3%A3o-geral)
- [Atividade 1: Temporizador Periódico](#atividade-1-temporizador-peri%C3%B3dico)
  - [Objetivo](#objetivo)
  - [Componentes Simulados](#componentes-simulados)
  - [Requisitos](#requisitos)
- [Atividade 2: Temporizador de Disparo Único (One Shot)](#atividade-2-temporizador-de-disparo-%C3%BAnico-one-shot)
  - [Objetivo](#objetivo-1)
  - [Componentes Simulados](#componentes-simulados-1)
  - [Requisitos](#requisitos-1)
- [Instruções de Uso](#instru%C3%A7%C3%B5es-de-uso)
- [Testes](#testes)
- [Ferramentas Utilizadas](#ferramentas-utilizadas)
- [Contribuição](#contribui%C3%A7%C3%A3o)
- [Licença](#licen%C3%A7a)

## Descrição Geral 📝
Esta tarefa consiste em duas atividades para implementar temporizações utilizando a biblioteca Pico SDK com o microcontrolador Raspberry Pi Pico W. Os objetivos são desenvolver um semáforo com temporização periódica e um sistema de acionamento de LEDs com temporização de disparo único.

## Atividade 1: Temporizador Periódico 🚦
### Objetivo 🎯
Projetar um semáforo com temporização de 3 segundos para cada alteração de sinal, utilizando a função `add_repeating_timer_ms()`.

### Componentes Simulados 🛠️
- Microcontrolador Raspberry Pi Pico W
- 03 LEDs (vermelho, amarelo e verde)
- 03 Resistores de 330 Ω

### Requisitos ✅
1. O semáforo deve iniciar na cor vermelha, alterar para amarela e, em seguida, verde.
2. Temporização ajustada para 3 segundos (3.000 ms).
3. Implementar a mudança de estado dos LEDs na função de callback `repeating_timer_callback()`.
4. Imprimir uma mensagem na porta serial a cada segundo.
5. Fazer um experimento com o LED RGB nos GPIOs 11, 12 e 13 utilizando a ferramenta BitDogLab.

## Atividade 2: Temporizador de Disparo Único (One Shot) 🔘
### Objetivo 🎯
Projetar um sistema de temporização para acionamento de LEDs a partir do clique em um pushbutton, utilizando a função `add_alarm_in_ms()`.

### Componentes Simulados 🛠️
- Microcontrolador Raspberry Pi Pico W
- 03 LEDs (azul, vermelho e verde)
- 03 Resistores de 330 Ω
- Botão (Pushbutton)

### Requisitos ✅
1. Ao pressionar o botão, os três LEDs devem ligar. Os LEDs devem desligar gradativamente (de três para dois, e depois para um).
2. Temporização ajustada para 3 segundos (3.000 ms) entre os estados dos LEDs.
3. Implementar a mudança de estado dos LEDs em funções de callback como `turn_off_callback()`.
4. O botão só deve alterar o estado dos LEDs quando o último LED for desligado.
5. Experimento com LED RGB nos GPIOs 11, 12 e 13 e o botão A no GPIO 05 usando BitDogLab.
6. Opcional: Implementar software debounce para atenuar o efeito bouncing do botão.

## Instruções de Uso 🖥️
1. Clone o repositório deste projeto no GitHub:
   ```bash
   git clone https://github.com/ateniltonjr/tarefa_29jan.git
   ```
2. Certifique-se de ter o VS Code configurado com a extensão Pico SDK e o simulador Wokwi.
3. Abra o projeto no VS Code.
4. Compile e carregue o código para o simulador Wokwi ou para a placa física.
5. Teste as funcionalidades conforme os requisitos das atividades.

  Outra alternativa:

1. Baixe o repositório em formato zip.
2. Extraia a pasta.
3. Mova para uma pasta de fácil acesso.
4. Importe a pasta com a extensão Raspberry pi pico disponivel no VS Code.
5. Compile o Programa.

## Testes 🔍
- Verifique a correta sequência dos LEDs para ambas as atividades.
- Garanta que os temporizadores respeitam os intervalos especificados.
- Certifique-se de que a mensagem é impressa corretamente na porta serial.
- Realize testes adicionais com LED RGB e pushbutton para validar o funcionamento completo.

## Ferramentas Utilizadas 🛠️
- Raspberry Pi Pico W
- Pico SDK
- Simulador Wokwi
- VS Code
- BitDogLab

## Contribuição 🤝
Esta é uma atividade individual, portanto, contribuições externas não são permitidas.

## Licença 📜
Este projeto é exclusivamente para propósitos educacionais conforme orientação do Professor Dr. Ricardo Menezes Prates.
