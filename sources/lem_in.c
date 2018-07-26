/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:52:26 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/18 19:52:28 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	free_farm(farm);
	// system("leaks lem-in");
	return (0);
}

int	read_and_set(t_farm **farm)
{
	char *after_rooms_line;

	*farm = newfarm();
	if (set_number_of_ants(farm) == -1)
		return (ANTS_ERROR);
	if ((after_rooms_line = set_rooms(farm)) == NULL)
		return (ROOM_ERROR);
	(*farm)->nodes = (*farm)->roomslst->id + 1;
	if (set_links(farm, after_rooms_line) < 0)
		return (LINK_ERROR);
	return (0);
}

int	analyze(t_farm *farm)
{
	if (set_all_ways(farm) < 0)
		return (-1);
	// top_ways = top_way(all_ways);
	return (1);
}

void	farm_error(int error)
{
	ft_printf("ERROR\n");
	error = 0;
}
