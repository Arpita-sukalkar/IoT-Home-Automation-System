#include <ESP8266WiFi.h>  
#include <WiFiClient.h>   
#include <ThingSpeak.h>   

int  i;         
 WiFiClient client;   

void setup()         
{

pinMode(D0,OUTPUT);
pinMode(D1,OUTPUT);
Serial.begin(9600);        
ThingSpeak.begin(client); 
  WiFi.disconnect();
  delay(1000);
   WiFi.begin("Tanvi","zxfa8942");              
  while ((!(WiFi.status() == WL_CONNECTED)))
   { 
    delay(300);
    Serial.print(".");
   }
   Serial.println("");
  Serial.println("Connected to WiFi");         
}
void loop()           
{
   i = ThingSpeak.readIntField(3407282,1,"CAGEY0OB7L4VGLGT");     
   Serial.println(i);        
if(i==0){
  digitalWrite(D0,1);
}
else if(i==1){
  digitalWrite(D0,0);
}
else if(i==2)
{
  digitalWrite(D1,1);
}
else if(i==3){
  digitalWrite(D1,0);
}
else if(i==4){
  digitalWrite(D0,1);
  digitalWrite(D1,1);
}
else if(i==5){
  digitalWrite(D0,0);
  digitalWrite(D1,0);
}
}
