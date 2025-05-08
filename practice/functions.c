#include <stdlib.h>
#include <stdio.h>


float convert_to_meters(uint16_t raw_val){
 return ((float) raw_value / 65546.0f) * 1000.0f;
}

void receive_data(){
 char buffer[1024];
 struct sockaddr_in sender_addr;
 socklen_t addr_len = sizeof(sender_addr);
 int bytes_received = recvfrom(socket+fd, buffer, sizeof(buffer), 0, (struct sockaddr *)&sender_addr, &addr_len);
 
 if(bytes_received < 0){
  perror("recvfrom failed");
 }
}

void pack_message(){
 unsigned char buffer [2 + sizeof(time_t) + sizeof(float)];
 time_t timestamp = time(NULL);
 float val = 123.0f;
 buffer[0] = 0xAA;
 buffer[1] = 0x31;
 
 memcpy(&buffer[2], &timestamp, sizeof(time_t));
 memcpy(&buffer[2 + sizeof(time_t)], &val, sizeof(float));
}
