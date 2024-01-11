#include <stdio.h>

int main(int ac, char **av, char **envp)
{
	int i = 0;
	while (i < 50)
	{
		printf("%s\n", envp[i]);
		i++;
	}
}
