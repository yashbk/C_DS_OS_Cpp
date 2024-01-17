#include <Arduino_FreeRTOS.h>

void setup() {
  Serial.begin(9600);
  xTaskCreate(myfunc,"Function description",128,NULL,1,NULL);
  xTaskCreate(myfunc_longdelay,"Delay",128,NULL,1,NULL);
}

void myfunc(void *some)
{
   pinMode(13,OUTPUT);
   while(1)
   {
    digitalWrite(13,digitalRead(13)^ 1);
    Serial.println("myfunc");
    delay(100);
   }
}

void myfunc_longdelay(void *some)
{
   pinMode(13,OUTPUT);
   while(1)
   {
    digitalWrite(13,digitalRead(13)^ 1);
    Serial.println("myfunclongdelay");
    delay(900);
   }
}

void loop() {
  // put your main code here, to run repeatedly:

}
