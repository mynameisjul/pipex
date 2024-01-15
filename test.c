#include "pipex.h"
#include <stdio.h>

int main(int ac, char **av, char **ev)
{
	
	int *fds;
	
	fds = (int []) {0, 1, 2, 3};
	ft_printinttab(fds, 4);
	fds = (int []) { fds[2], fds[3], -1, -1};
	ft_printinttab(fds, 4);
	//free(fds);
	return (0);
}
