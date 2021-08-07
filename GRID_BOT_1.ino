#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
/* import the code for running the motors based on the data from the tinkercad simulation file*/
RF24 radio(7, 8);               // nRF24L01 (CE,CSN)
String data_receive;
RF24Network network(radio);      // Include the radio in the network

const uint16_t this_node = 01;   // Address of our node in Octal format ( 04,031, etc)
const uint16_t master00 = 00;    // Address of the other node in Octal format

void setup() {
  // put your setup code here, to run once:
  SPI.begin();
  radio.begin();
  network.begin(90, this_node); //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
}

void loop() {
  // put your main code here, to run repeatedly:
  network.update();
  while ( network.available() ) {
    RF24NetworkHeader header;
    network.read(header, &data_receive, sizeof(data_receive)); // Read the incoming data
  }
}
