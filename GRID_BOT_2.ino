#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
/*Import the DC motor code and connection from the tinkercad simulation file*/
RF24 radio(7, 8);               // nRF24L01 (CE,CSN)

RF24Network network(radio);      // Include the radio in the network

const uint16_t this_node = 02;   // Address of our node in Octal format ( 04,031, etc)
const uint16_t master00 = 00;    // Address of the other node in Octal format
String data_receive;

void setup(){
  SPI.begin();
  radio.begin();
  network.begin(90, this_node); //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
}

void loop() {
 network.update();
  while ( network.available() ) {
    RF24NetworkHeader header;
    network.read(header, &data_receive, sizeof(data_receive));} // Read the incoming data
  delay(5);
}
