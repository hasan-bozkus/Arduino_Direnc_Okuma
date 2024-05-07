#include <IRremote.h> 

int kumandapin = 12;

int i;
  
IRrecv kizilotesi(kumandapin);

decode_results veri;

void setup() {

   Serial.begin(9600);
  kizilotesi.enableIRIn();
  for(i = 2; i<=7; i++)
  {
      pinMode(i, OUTPUT);
  }
}

void loop() {
    if(kizilotesi.decode(&veri))
    {

      switch(veri.value)
      {
        case 0x1:
          for(i = 2; i<7; i++)
          {
            digitalWrite(i, LOW);
          }
            digitalWrite(2, HIGH);
            Serial.print("Birinci butona basıldı");
            break;
      }
      kizilotesi.resume();
    }

    delay(1000);
}
