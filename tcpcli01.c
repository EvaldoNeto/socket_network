#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <arpa/inet.h>

#include "./libft/libft.h"

void str_cli(FILE *fp, int sockfd)
{
  char sendline[4096];
  char **recvline;

  recvline = (char **)ft_memalloc(sizeof(char *));
  while (fgets(sendline, 4096, fp) != NULL)
    {
      write(sockfd, sendline, strlen(sendline));
      get_next_line(sockfd, recvline);
      fputs(*recvline, stdout);
      free(*recvline);
      ft_putchar('\n');;
    }
  free(recvline);
}

int main(int argc, char **argv)
{
  int                sockfd;
  struct sockaddr_in servaddr;

  if (argc != 2)
    {
      printf("error: wrong number of arguments");
      return (0);
    }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(9877);
  inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

  connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
  str_cli(stdin, sockfd);

  exit(0);
}
