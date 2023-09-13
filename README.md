# smart-tracking

## 🌐 The Project
PoC (Proof of Concept) baseado na plataforma Arduino UNO R3 que permite medir os valores médios de luminosidade, temperatura e umidade de um ambiente.

## 🚀 Technologies

Componentes:
• Arduino Uno ou similar.
• Sensor DHT11 para medição de temperatura e umidade.
• Sensor de luminosidade (LDR).
• Display LCD com conexão I2C.
• Buzzer para reproduzir sons.
• LEDs conectados a pinos digitais (neste código, um LED vermelho).

Bibliotecas:
• "dht.h" (para o sensor DHT11).
• "RTClib.h" (para o RTC DS3231).
• "LiquidCrystal.h" (para o display LCD).
• "Wire.h" (para comunicação I2C).
• "EEPROM.h" (para gravar dados na EEPROM).
 
## 💻 Manual de Operação
• Conexões Físicas:
Conectar os componentes aos pinos definidos no código (LDR, DHT11,
BUZZER, LEDs, etc.).
Conectar o display LCD usando uma conexão I2C, geralmente SDA e SCL.
• Inicialização:
Quando você liga o Arduino, ele inicializa os componentes, como o RTC, display
LCD e define os pinos como entrada/saída. </br>
• Tela de Inicialização:
Durante a inicialização, a tela LCD mostra uma animação com caracteres
personalizados (FESA e um coração).
MANUAL DE OPERAÇÃO
• Medição Ambiental:
O código faz leituras da temperatura, umidade e luminosidade dos sensores
DHT11 e LDR.
Calcula médias dessas leituras ao longo de um intervalo (1 minuto) e exibe as
médias no display LCD.
As leituras são impressas na porta serial também.
• RTC (Relógio em Tempo Real):
O código lê a data e hora do RTC DS3231 e as exibe no display LCD e na porta
serial.
• Indicadores:
Com base nas leituras de temperatura, umidade e luminosidade, o código
controla um LED vermelho e gera um som no buzzer.
Se os valores estiverem dentro de certos intervalos, o LED vermelho fica
apagado.
Caso contrário, o LED vermelho fica aceso e o buzzer emite um som agudo.
• Reset de Médias:
Após cada intervalo de leitura, as médias são reiniciadas.
• Ciclo Principal:
O código fica em um loop, continuamente medindo e exibindo os dados
ambientais e de tempo, controlando indicadores e reiniciando as médias.
• Notas Adicionais:
MANUAL DE OPERAÇÃO
Este código grava valores nas posições da EEPROM, mas parece estar fazendo
isso de maneira incorreta. Você pode precisar ajustar essa parte do código.
• Fim do Programa:
O código repete esse ciclo continuamente, a menos que haja um erro durante a
inicialização do RTC, caso em que ele fica preso em um loop infinito.

## 🖥️ Design
