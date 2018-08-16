#include <stdio.h>
#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void test_1full_file()
{
  char **line;

  int fd1;
  line = (char **)ft_memalloc(sizeof(char*));
  fd1 = open("TCPClient.c", O_RDONLY);

  while (get_next_line(fd1, line))
    {
      ft_putstr(*line);
      free(*line);
      ft_putchar('\n');
    }
  free(line);
}

int main()
{
  test_1full_file();

  return (0);
}
