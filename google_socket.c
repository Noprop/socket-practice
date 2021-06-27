#include <stdio.h>
#include <string.h>
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
  server.sin_port = htons(80);
  // server.sin_port = htons(443);

  int connection_status = connect(network_socket, (struct sockaddr*) &server, sizeof(server));

  if (connection_status == -1) {
    printf("Error connecting to server.");
    return 0;
  }

  printf("Connected to server\n");

  char *message;
  message = "GET / HTTP/1.1\r\n\r\n";

  int send_status = send(network_socket, message, strlen(message), 0);

  if (send_status == -1) {
    printf("Send failed.");
    return 0;
  }

  printf("Message sent.\n");

  char server_reply[2000];
  int receive_status = recv(network_socket, server_reply, 2000, 0);

  if (receive_status == -1) {
    printf("Receive failed.");
  }

  printf("Reply received: %s\n", server_reply);

  return 0;
}