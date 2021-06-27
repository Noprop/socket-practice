#include <stdio.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

int main () {
  int network_socket;
  network_socket = socket(AF_INET, SOCK_STREAM, 0);

  if (network_socket == -1) {
    printf("Could not create socket.");
  }

  struct sockaddr_in server;
  server.sin_addr.s_addr = inet_addr("74.125.136.139");
  server.sin_family = AF_INET;
  server.sin_port =  htons(80);

  int connection_status = connect(network_socket, (struct sockaddr*) &server, sizeof(server));

  if (connection_status == -1) {
    printf("Error connecting to server.");
    return 0;
  }

  printf("Connected to server");

  return 0;
}