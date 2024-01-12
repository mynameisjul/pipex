#include "pipex.h"
#include <stdio.h>

int main(int ac, char **av, char **ev)
{
	
	int fdio[2];
	process_fdio(&fdio[0], &fdio[1], ac, av);
	ft_printf("%d\n%d\n", fdio[0], fdio[1]);
	return (0);
}
