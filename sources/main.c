#include "../headers/lem_in.h"

int		main(int ac, char **av)
{
	t_farm	*farm;
	int		error;

	farm = NULL;
	if ((error = read_and_set(&farm)) < 0)
	{
		farm_error(error, farm);
		return (0);
	}
	if (analyze(farm) < 0)
	{
		farm_error(error, farm);
		return (0);
	}
	show_process(farm, ac, av);
    ants_moving(farm);
	free_farm(farm);
    system("leaks lem-in");
	return (0);
}