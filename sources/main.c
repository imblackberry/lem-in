#include "../headers/lem_in.h"

int		main()
{
	t_farm	*farm;
	int		error;

	farm = NULL;
	if ((error = read_and_set(&farm)) < 0)
	{
		free_farm(farm);
		farm_error(error);
		return (0);
	}



	
	ft_putstr(farm->file);
	showroomslst(farm->roomslst);
	show_int_arr(farm->map, farm->nodes, farm->nodes);
	ft_printf("\033[0;33mSTART ROOM id = [%d]\n", farm->id_start);
	ft_printf("END ROOM id = [%d]\n\033[0m", farm->id_end);	




	if (analyze(farm) < 0)
		farm_error(error);
    show_each_ant_way(farm->top, farm->ants);
	free_farm(farm);
    system("leaks lem-in");
	return (0);
}