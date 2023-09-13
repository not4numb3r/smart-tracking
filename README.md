# smart-tracking

## 🌐 O Projeto
PoC (Proof of Concept) baseado na plataforma Arduino UNO R3 que permite medir os valores médios de luminosidade, temperatura e umidade de um ambiente.

## 🚀 Tecnologias

<b>Componentes </b>: </br>
• Arduino Uno ou similar. </br>
• Sensor DHT11 para medição de temperatura e umidade. </br>
• Sensor de luminosidade (LDR). </br>
• Display LCD com conexão I2C. </br>
• Buzzer para reproduzir sons. </br>
• LEDs conectados a pinos digitais (neste código, um LED vermelho). </br>

<b>Bibliotecas</b>: </br>
• "dht.h" (para o sensor DHT11). </br>
• "RTClib.h" (para o RTC DS3231). </br>
• "LiquidCrystal.h" (para o display LCD). </br>
• "Wire.h" (para comunicação I2C). </br>
• "EEPROM.h" (para gravar dados na EEPROM). </br>
 
## 💻 Manual de Operação
➡️ Conexões Físicas:
Conectar os componentes aos pinos definidos no código (LDR, DHT11,
BUZZER, LEDs, etc.). 
Conectar o display LCD usando uma conexão I2C, geralmente SDA e SCL. </br></br>
➡️ Inicialização:
Quando você liga o Arduino, ele inicializa os componentes, como o RTC, display
LCD e define os pinos como entrada/saída. </br></br>
➡️ Tela de Inicialização:
Durante a inicialização, a tela LCD mostra uma animação com caracteres
personalizados (FESA e um coração). </br></br>
➡️ Medição Ambiental:
O código faz leituras da temperatura, umidade e luminosidade dos sensores
DHT11 e LDR.
Calcula médias dessas leituras ao longo de um intervalo (1 minuto) e exibe as
médias no display LCD.
As leituras são impressas na porta serial também. </br></br>
➡️ RTC (Relógio em Tempo Real):
O código lê a data e hora do RTC DS3231 e as exibe no display LCD e na porta
serial. </br></br>
➡️ Indicadores:
Com base nas leituras de temperatura, umidade e luminosidade, o código
controla um LED vermelho e gera um som no buzzer.
Se os valores estiverem dentro de certos intervalos, o LED vermelho fica
apagado.
Caso contrário, o LED vermelho fica aceso e o buzzer emite um som agudo. </br></br>
➡️ Reset de Médias:
Após cada intervalo de leitura, as médias são reiniciadas. </br></br>
➡️ Ciclo Principal:
O código fica em um loop, continuamente medindo e exibindo os dados
ambientais e de tempo, controlando indicadores e reiniciando as médias. </br></br>
➡️ Notas Adicionais:
Este código grava valores nas posições da EEPROM, mas parece estar fazendo
isso de maneira incorreta. Você pode precisar ajustar essa parte do código. </br></br>
➡️ Fim do Programa:
O código repete esse ciclo continuamente, a menos que haja um erro durante a 
inicialização do RTC, caso em que ele fica preso em um loop infinito. </br></br>

## 🖥️ Design
<img src="/img/design.png">
