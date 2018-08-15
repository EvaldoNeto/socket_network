#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>
#include <strings.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <arpa/inet.h>

void str_echo(int sockfd)
{
  ssize_t n;
  char buf[4096];

  while ((n = read(sockfd, buf, 4096)) > 0)
    {
      write(sockfd, buf, n);
    }
}

int main()
{
  int                listenfd;
  int                connfd;
  pid_t              childpid;
  socklen_t          clilen;
  struct sockaddr_in cliaddr;
  struct sockaddr_in servaddr;

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(9877);

  bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

  listen(listenfd, 1024);

  while(true)
    {
      clilen = sizeof(cliaddr);
      connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);

      if ((childpid = fork()) == 0)
	{
	  close(listenfd);
	  str_echo(connfd);
	  exit(0);
	}
      close(connfd);
    }
}
