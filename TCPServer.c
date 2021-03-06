#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

/**
 * Basic TCP server, code from https://www.youtube.com/watch?v=LtXEMwSG5-8&feature=youtu.be
 */

int main()
{
  char server_message[256] = "You have reached the server!";

  /**
   * Create the server socket
   */
  int server_socket;

  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  /**
   * Define the server address
   */
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(8001);
  server_address.sin_addr.s_addr = INADDR_ANY;

  /**
   * Bind the socket to our specified IP and port
   */
  bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

  listen(server_socket, 5);

  int client_socket;
  client_socket = accept(server_socket, NULL, NULL);

  send(client_socket, server_message, sizeof(server_message), 0);

  /**
   * Close the socket
   */
  close(server_socket);
  return (0);
}
