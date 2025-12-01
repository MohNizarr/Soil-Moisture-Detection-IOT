#include<ESP8266WiFi.h> //Memasukkan Library ESP8266 dan blynk
#include<BlynkSimpleEsp8266.h>  

#define BLYNK_PRINT Serial //Mendefinisikan blynk serial dan LED D4
#define LED D4

BlynkTimer timer;

char auth[] ="jByzeQ1BsKi0x_JDBrKDHLlM-AWR0Q4a"; //Auth Token Blynk
char ssid[] ="Andromax-M2Y-707C"; //Nama WiFi
char pass[] ="27041633"; //Nama Password

void myTimeEvent()
{
 int adc = analogRead(A0); //Mendefinisikan sebuah keluaran analog pada pin A0
  int persentase = (100 - ((adc/1023.00) * 100)); //Perhitungan untuk mencari persentase kelembaban
  float tegangan = adc * (5.0 / 1023.0); //Perhitungan untuk mencari tegangan
  Blynk.virtualWrite(V0, persentase); //PIN V0 sebagai persentase
  Blynk.virtualWrite(V1, tegangan); //PIN V1 sebagai Tegangan
}
void setup() 
{
Serial.begin(115200);
Blynk.begin(auth ,ssid ,pass);
timer.setInterval(1000L, myTimeEvent); //1000L = 1 Detik
pinMode(LED, OUTPUT);
}

void loop()
{
  if(analogRead(A0) <= 500){ 
    Serial.println("Kondisi tanah basah");
    digitalWrite(LED, LOW); //Jika kondisi tanah basah maka led akan mati
  }
  else{
    Serial.println("Kondisi tanah sudah mulai kering");
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW); //Jika tanah kering maka led akan berkedip
    delay(500);
  }

Blynk.run();
timer.run();
}
