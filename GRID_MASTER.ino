#include <SPI.h>  
#include "RF24.h"
#include <nRF24L01.h>
#include <RF24Network.h>

//transmitter code

RF24 radio(7, 8);               /* nRF24L01 (CE,CSN)*/
RF24Network network(radio);

const uint16_t this_node = 00;
const uint16_t node01 = 01;
const uint16_t node02 = 02;
String data;
void setup()
{
  Serial.begin(9600);
  SPI.begin();
  radio.begin();
  network.begin(90, this_node);  /*(channel, node address)*/
  radio.setDataRate(RF24_2MBPS);
}

void loop()
{
  while (Serial.available() == 0){};
  data = Serial.readString();
  if (data.charAt(0)==1){
    /*Sending data to Bot 1, here it is Node 01*/
    RF24NetworkHeader header2(node01);     
    bool ok = network.write(header2, &data, sizeof(data)); 
    }
   if (data.charAt(0)==2){
    /*Sending data to Bot 2, here it is Node 02*/
    RF24NetworkHeader header3(node02); 
    bool ok2 = network.write(header3, &data, sizeof(data)); 
    }
    delay(5);
}
