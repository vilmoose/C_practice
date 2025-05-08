#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 9000
#define BUFFER_SIZE 1024


int main(){
 int server_socket;
 struct sockaddr_in server_addr, client_addr;
 char buffer[BUFFER_SIZE];
 socklen_t addr_len = sizeof(client_addr);
 
 server_socket = socket(AF_INET, SOCK_DGRAM, 0);
 if (server_socket < 0){
  perror("Server socket failed to create");
  exit(EXIT_FAILURE);
 }
 
 memset(&server_addr, 0, sizeof(server_addr));
 server_addr.sin_family = AF_INET;
 server_addr.sin_addr.s_addr = INADDR_ANY;
 server_addr.sin_port = htons(PORT);
 
 if(bind(server_socket, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
  perror("Bind failed");
  close(server_socket);
  exit(EXIT_FAILURE);
 }
 
 printf("UDP TS Echo Server listening on port %d...\n", server_addr.sin_port);
 
 while(1){
  int bytes_received = recvfrom(server_socket, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &addr_len);
  
  if(bytes_received < 0){
   perror("Bytes failed to received");
  } 
  
  buffer[bytes_received] = '\0';
  
  char client_ip[INET_ADDRSTRLEN];
  inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
  int client_port = ntohs(client_addr.sin_port);
  
  printf("Recieved %d from %s:%d\n", bytes_received, client_ip, client_port);
  printf("Data: %s\n", buffer);
  
  time_t timestamp = time(NULL);
  printf("Adding timestamp: %ld\n", timestamp);
  
  char reply[BUFFER_SIZE + sizeof(time_t)];
  memcpy(reply, buffer, bytes_received);
  memcpy(reply + bytes_received, &timestamp, sizeof(time_t));
  
  int bytes_sent = sendto(server_socket, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, addr_len);
  
  if(bytes_sent < 0){
   perror("sendto failed");
  } else {
   printf("Sent %d bytes back to client\n", bytes_sent);
  }
 }
 close(server_socket);
 return 0;

}
