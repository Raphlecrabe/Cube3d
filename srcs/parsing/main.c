#include "../../incs/parsing.h"

int	main(int argc, char **argv)
{
	t_cube	*cube;
	t_memory	*mem;

	if (argc != 2)
	{
		write(2, "Error, please use only one argument\n", 37);
		return (0);
	}
	if (ft_initcube(&cube, mem) == -1)
		return (0);
	if (ft_fullparse(cube, argv) == -1)
		return (0);
	//la suite plus tard
}
