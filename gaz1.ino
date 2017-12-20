#include <dht.h>
dht DHT;

#define DHT11_PIN 6


int sensor=0; //Sensör arduinonun analog 1 pinine bağlandı.
int led1=8; // LED 8. dijital çıkış pinine bağlandı.
int led2=7; // LED 7. dijital çıkış pinine bağlandı.
int gas_limite; // Gaz limiti değişkeni tanımlandı.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Seri haberleşme ekranına bağlanma kodu.
  pinMode(sensor, INPUT); // Sensör giriş yapıldı.
  pinMode(led1, OUTPUT); // LED çıkış yapıldı.
  pinMode(led2, OUTPUT); // LED çıkış yapıldı.
}

void loop() {

  int chk = DHT.read11(DHT11_PIN);
  gas_limite=analogRead(sensor); // Sensörden değer okunuyor.
  Serial.print("SICAKLIK = ");
  Serial.println(DHT.temperature);
  Serial.print("NEM = ");
  Serial.println(DHT.humidity);
  Serial.print("Gaz Durumu: "); // Seri haberleşme ekranında Gaz Durumu yazısı yazdırıldı.
  Serial.print(gas_limite); // Seri haberleşme ekranında gaz limiti değeri gösteriliyor.
  Serial.println(" Limit"); // Seri haberleşme ekranında okunan değerin yanına Limit yazdırıldı.
  delay(1500); 

   
  if (gas_limite>200 || DHT.temperature>30 ||DHT.humidity>30){ // Gaz limiti ayarı yapıldı. İstediğiniz değeri yapabilirsiniz. Gaz limiti 270'den büyükse...
    if(gas_limite>200){
      Serial.print("!...................................GAZ ALARM DURUMU...........................!\n");
        digitalWrite(led1, LOW); // Mavi LED lojik 0 yapıldı.
        digitalWrite(led2, HIGH); // Kırmızı LED lojik 1 yapıldı.      
    }
    else if(DHT.temperature>28){
      Serial.print("!................................SICAKLIK ALARM DURUMU...........................!\n"); 
        digitalWrite(led1, LOW); // Mavi LED lojik 0 yapıldı.
        digitalWrite(led2, HIGH); // Kırmızı LED lojik 1 yapıldı.     
    }
    else if(DHT.humidity>30){
      Serial.print("!...................................NEM ALARM DURUMU...........................!\n"); 
        digitalWrite(led1, LOW); // Mavi LED lojik 0 yapıldı.
        digitalWrite(led2, HIGH); // Kırmızı LED lojik 1 yapıldı.     
    }
   } 
  else{ // Eğer limitler Normal ise.
  Serial.println("..................................Tüm Değerler Normal........................");
    
  digitalWrite(led1, HIGH); // Mavi LED lojik 1 yapıldı.
  digitalWrite(led2, LOW); // Kırmızı LED lojik 0 yapıldı.
}

}
