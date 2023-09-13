#include "dht.h" //necessario instalar essas libs
#include <LiquidCrystal.h> //INCLUSÃO DA BIBLIOTECA
#include <Wire.h> //INCLUSÃO DA BIBLIOTECA
#include "RTClib.h" //necessario instalar essas libs
#include <EEPROM.h> //INCLUSÃO DA BIBLIOTECA
RTC_DS3231 rtc; //OBJETO rtc DO TIPO RTC_DS3231 (para conseguir chamar as funções do rtc)

 

char daysOfTheWeek[7][12] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"}; //dias da semana para o rtc

 

 

//COMPONENTES
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2); // Display
const int LDR_PIN = A1; // Respectivas portas que os componentes estão associados (LDR, DHT, Alarme sonoro(buzzer), led vermelho e led verde)
const int pinoDHT11 = A2;
const int BUZZER_PIN = 13;
int ledVermelho = 7;
bool inicio = true;

 

//VARIÁVEIS

 

 

dht DHT; //OBJETO dht DO TIPO DHT (para conseguir chamar as funções do dht)

 

 

int temperatura = 0; //declaração de variáveis

 

int umidade = 0;

 

int luminosidade = 0;

 

 

 

int temperaturaMedia = 0; //declaração de variáveis para as médias

 

int umidadeMedia = 0;

 

int luminosidadeMedia = 0;

 

int leituras = 0;

 

 

 

unsigned long intervalo = 60000; //intervalo de 1 minuto para cálculo das médias

 

unsigned long ultimaLeitura = 0; //variável para salvar ultima leitura

 

 

 

//Impressão do nome FESA na tela.

 

 

byte fesa[8] = {
  B11111,
  B10000,
  B10000,
  B11111,
  B10000,
  B10000,
  B10000,
  B10000
};

 

 

byte fesa2[8] = {
  B11111,
  B10000,
  B10000,
  B11111,
  B11111,
  B10000,
  B10000,
  B11111
};

 

 

byte fesa3[8] = {
  B11111,
  B10000,
  B10000,
  B11111,
  B11111,
  B00001,
  B00001,
  B11111
};

 

 

byte fesa4[8] = {
  B11111,
  B10001,
  B10001,
  B11111,
  B11111,
  B10001,
  B10001,
  B10001
};

 

byte coracao[8] = {
  0B00000,
  0B01010,
  0B11111,
  0B11111,
  0B11111,
  0B01110,
  0B00100,
  0B00000
};


 

 

void setup()

 

{

 

//inicialização dos componentes (INPUT = Entrada de dados / OUTPUT = Saída de dados)

 

  rtc.begin();

 

  Serial.begin(9600);

 

  lcd.begin(16, 2);

 

  pinMode(LDR_PIN, INPUT);

 

  pinMode(pinoDHT11, INPUT);

 

  pinMode(BUZZER_PIN, OUTPUT);

 

 

  pinMode(ledVermelho, OUTPUT);

 

 

//Atrela um byte "desenhado" antes a um char (vai de 0 até 7, ou seja, 8 bytes

 

  lcd.createChar(0, fesa);

 

  lcd.createChar(1, fesa2);

 

  lcd.createChar(2, fesa3);

 

  lcd.createChar(3, fesa4);

 

  lcd.createChar(4, coracao);

 

 

  if(!rtc.begin()) { // SE O RTC NÃO FOR INICIALIZADO, FAZ

 

    Serial.println("DS3231 não encontrado"); //IMPRIME O TEXTO NO MONITOR SERIAL

 

    while(1); //SEMPRE ENTRE NO LOOP

 

  }

 

  if(rtc.lostPower()){ //SE RTC FOI LIGADO PELA PRIMEIRA VEZ

 

    Serial.println("DS3231 OK!"); //IMPRIME O TEXTO NO MONITOR SERIAL

 

    rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //CAPTURA A DATA E HORA EM QUE O SKETCH É COMPILADO

 

  }

 

  delay(100); //INTERVALO DE 100 MILISSEGUNDOS

 

 

 

//  for (int i = 0; i < 255; i++)

 

//    EEPROM.write(i, i);

 

}

 

//

 

void loop()

 

{

 

  if (inicio) //FESA

 

  {

 

    lcd.setCursor(0, 0);  

 

    lcd.write(byte(0));

 

    lcd.setCursor(1, 0);  

 

    lcd.write(byte(1));

 

    lcd.setCursor(2, 0);  

 

    lcd.write(byte(2));

 

    lcd.setCursor(3, 0);

 

    lcd.write(byte(3));

 

    lcd.setCursor(0, 1);  

 

    lcd.write(byte(4));

 

    lcd.setCursor(1, 1);  

 

    lcd.write(byte(5));

 

    lcd.setCursor(2, 1);

 

    //lcd.write(byte(6));

 

    lcd.setCursor(3, 1);

 

    lcd.write(byte(5));

 

    delay(1000);

 

    lcd.clear();

 

    lcd.setCursor(4, 0);  

 

    lcd.write(byte(0));

 

    lcd.setCursor(5, 0);  

 

    lcd.write(byte(1));

 

    lcd.setCursor(6, 0);  

 

    lcd.write(byte(2));

 

    lcd.setCursor(7, 0);

 

    lcd.write(byte(3));

 

    lcd.setCursor(4, 1);  

 

    lcd.write(byte(4));

 

    lcd.setCursor(5, 1);  

 

    lcd.write(byte(5));

 

    lcd.setCursor(6, 1);  

 

    //lcd.write(byte(6));

 

    lcd.setCursor(7, 1);

 

    lcd.write(byte(5));

 

    delay(1000);

 

    lcd.clear();

 

    lcd.setCursor(8, 0);  

 

    lcd.write(byte(0));

 

    lcd.setCursor(9, 0);  

 

    lcd.write(byte(1));

 

    lcd.setCursor(10, 0);  

 

    lcd.write(byte(2));

 

    lcd.setCursor(11, 0);

 

    lcd.write(byte(3));

 

    lcd.setCursor(8, 1);  

 

    lcd.write(byte(4));

 

    lcd.setCursor(9, 1);  

 

    lcd.write(byte(5));

 

    lcd.setCursor(10, 1);  

 

    //lcd.write(byte(6));

 

    lcd.setCursor(11, 1);

 

    lcd.write(byte(5));

 

    delay(1000);

 

    lcd.clear();

 

    lcd.setCursor(12, 0);  

 

    lcd.write(byte(0));

 

    lcd.setCursor(13, 0);  

 

    lcd.write(byte(1));

 

    lcd.setCursor(14, 0);  

 

    lcd.write(byte(2));

 

    lcd.setCursor(15, 0);

 

    lcd.write(byte(3));

 

    lcd.setCursor(12, 1);  

 

    lcd.write(byte(4));

 

    lcd.setCursor(13, 1);  

 

    lcd.write(byte(5));

 

    lcd.setCursor(14, 1);  

 

    lcd.write(byte(5));

 

    lcd.setCursor(15, 1);

    lcd.write(byte(5));

    delay(1000);

 

    lcd.clear();

 

    delay(1000);

 

 

    inicio = false; //fim do loop

 

  }

 

 

// DHT(Leituras e médias)

 

 

//faz as leituras das respectivas variáveis

 

  DHT.read11(pinoDHT11);

 

  int temperaturaAtual = DHT.temperature;

 

  int umidadeAtual = DHT.humidity;

 

//conversão da luminosidade para adquirir o valor correto

 

  int valor_luminosidade = analogRead(LDR_PIN);

 

  int luminosidadeAtual = map(valor_luminosidade, 0, 1023, 100 , 0);

 

 

//cálculo da média

 

  temperaturaMedia += temperaturaAtual;

 

  umidadeMedia += umidadeAtual;

 

  luminosidadeMedia += luminosidadeAtual;

 

  leituras++;

 

 

  unsigned long tempoAtual = millis();

 

  if(tempoAtual - ultimaLeitura >= intervalo){

 

    temperaturaMedia /= leituras;

 

    umidadeMedia /= leituras;

 

    luminosidadeMedia /= leituras;

 

 

 

//exibição na serial

 

    Serial.print("Temperatura: ");

 

    Serial.print(temperaturaMedia);

 

    Serial.println(" °C");

 

    Serial.print("Umidade: ");

 

    Serial.print(umidadeMedia);

 

    Serial.println(" %");

 

    Serial.print("Luminosidade: ");

 

    Serial.print(luminosidadeMedia);

 

    Serial.println(" %");

 

 

  }

 

 

//LEITURAS DO RTC:

 

 

  DateTime now = rtc.now(); //CHAMADA DE FUNÇÃO

 

  Serial.print("Data: "); //IMPRIME O TEXTO NO MONITOR SERIAL

 

  Serial.print(now.day(), DEC); //IMPRIME NO MONITOR SERIAL O DIA

 

  Serial.print('/'); //IMPRIME O CARACTERE NO MONITOR SERIAL

 

  Serial.print(now.month(), DEC); //IMPRIME NO MONITOR SERIAL O MÊS

 

  Serial.print('/'); //IMPRIME O CARACTERE NO MONITOR SERIAL

 

  Serial.print(now.year() % 100); //IMPRIME NO MONITOR SERIAL O ANO

 

  Serial.print(" / Dia: "); //IMPRIME O TEXTO NA SERIAL

 

  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]); //IMPRIME NO MONITOR SERIAL O DIA

 

  Serial.print(" / Horas: "); //IMPRIME O TEXTO NA SERIAL

 

  Serial.print(now.hour(), DEC); //IMPRIME NO MONITOR SERIAL A HORA

 

  Serial.print(':'); //IMPRIME O CARACTERE NO MONITOR SERIAL

 

  Serial.print(now.minute(), DEC); //IMPRIME NO MONITOR SERIAL OS MINUTOS

 

  Serial.print(':'); //IMPRIME O CARACTERE NO MONITOR SERIAL

 

  Serial.println(now.second(), DEC); //IMPRIME NO MONITOR SERIAL OS SEGUNDOS

 

  Serial.println(); //QUEBRA DE LINHA NA SERIAL

 

  delay(1000); //INTERVALO DE 1 SEGUNDO

 

 

 

//LCD

 

 

  lcd.setCursor(1,0);

 

  lcd.write("T");

 

  lcd.print(temperaturaMedia);

 

  //lcd.write(" ");

 

  lcd.write("C");

 

  lcd.setCursor(7,0);

 

  lcd.write("L");

 

  lcd.print(luminosidadeMedia);

 

  lcd.write("% ");

 

  lcd.setCursor(12,0);

 

  lcd.write("U");

 

  lcd.print(umidadeMedia);

 

  lcd.write("%");

 

  lcd.setCursor(0,2);

 

  lcd.print(now.day());

 

  lcd.write("/");

 

  lcd.print(now.month());

 

  lcd.write("/");

 

  lcd.print(now.year()%100);

 

  lcd.setCursor(10,2);

 

  lcd.print(now.hour());

 

  lcd.write(":");

 

  lcd.print(now.minute());

 

  //lcd.write(":");

 

  //lcd.print(now.second());

 

 

 

//INDICADORES

 

 

 

    if(luminosidadeMedia < 30 && luminosidadeMedia > 0 && temperaturaMedia > 15 && temperaturaMedia < 25 && umidadeMedia > 30 && umidadeMedia < 50 )

 

  {

 

    digitalWrite(ledVermelho, LOW);

 

 

  }  

 

  else

 

  {

 

 

    digitalWrite(ledVermelho, HIGH);

 

    for (int i = 0; i < 255; i++)

 

      EEPROM.write(i, luminosidadeMedia && temperaturaMedia && umidadeMedia);

 

    // Gere um som de frequência 2000Hz (tom agudo) por 500ms

 

    tone(BUZZER_PIN, 2000);

 

    delay(2000);

 

 

    // Pare o som por 100ms

 

    noTone(BUZZER_PIN);

 

    delay(100);

 

  }

 

 

  //zera as variáveis e a leitura

 

    temperaturaMedia = 0;

 

    umidadeMedia = 0;

 

    luminosidadeMedia = 0;

 

    leituras = 0;

 

 

    ultimaLeitura = tempoAtual;

 

 

 

  delay(2000);  //iterate every 5 seconds

 

 

 

}
