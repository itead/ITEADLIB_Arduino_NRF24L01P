/* Send Demo */
#include <SPI.h>
#include <NRF24L01P.h>

NRF24L01P rf24l01p;
uint8_t buffer[24];
uint8_t to[5] = {0x11,0x22,0x33,0x44,0x02}; /* Must be 5 Byte */
uint8_t addr[5] = {0x11,0x22,0x33,0x44,0x01}; /* Must be 24 Byte */
int8_t ret;

void setup()
{
    Serial.begin(9600);
    rf24l01p.begin(9,10,PWR_0dBm,AIR_RATE_2Mbps,50,addr);
}

void loop()
{
    static uint8_t base=0;
    base ++;
    
    for(int i=0;i<24;i++)
        buffer[i] = i + base;
    
    ret = rf24l01p.send_packet(to,buffer);
    Serial.print("ret = ");
    Serial.println(ret);
    
    Serial.print("Send(Hex):");
    for(int i=0;i<24;i++) {
        Serial.print(buffer[i],HEX);
        Serial.print(" ");
    }
    Serial.println("End");
    
    delay(1000);
   
}
