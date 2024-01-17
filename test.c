#include <stdio.h>
#include "pipex.h"

int main(int ac, char **av)
{
	char	*str;
	int i = 0;

	i = here_doc_file(av[1]);
	while (oget_next_line(i, &str) != 0)
		ft_printf("%s", str);
	return (0);
}
