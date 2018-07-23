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

void	show_int_arr(int **arr, int size_i, int size_j)
{
	int i;
	int j;

	size_i++;
	size_j++;
	i = 0;
	j = 0;
	arr[1] = arr[1];
	ft_printf("\033[0;32m\t");
	while (j < size_j)
	{
		ft_printf("id[%d]\t", j + 1);
		j++;
	}
	ft_printf("\n");
	while (i < size_i)
	{
		j = 0;
		ft_printf("id[%d]", i + 1);
		while (j < size_j)
		{
			ft_printf("\t|%d|", arr[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("___________________________________________________________________________________________________________________________________\n\033[0m");
}

void	showroomslst(t_roomslst *roomslst)
{
	while (roomslst != NULL)
	{
		ft_printf("\033[0;34mid = %d\tname = %s\n\033[0m", roomslst->id, roomslst->name);
		roomslst = roomslst->next;
	}
}

int		main()
{
	t_farm	*farm;
	int		error;

	farm = NULL;
	if ((error = read_and_set(&farm)) < 0)
	{
		farm_error(error);
		return (0);
	}




	ft_putstr(farm->file);
	showroomslst(farm->roomslst);
	show_int_arr(farm->map, farm->roomslst->id, farm->roomslst->id);
	ft_printf("\033[0;33mSTART ROOM id = [%d]\n", farm->id_start);
	ft_printf("END ROOM id = [%d]\n\033[0m", farm->id_end);	






	if ((farm->top_ways = analyze(farm)) == NULL)
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
	(*farm)->nodes = (*farm)->roomslst->id;
	if (set_links(farm, after_rooms_line) < 0)
		return (LINK_ERROR);
	return (0);
}

t_way	*analyze(t_farm *farm)
{
	t_way *all_ways;
	t_way *top_ways;

	top_ways = NULL;
	if ((all_ways = set_all_ways(all_ways, farm)) == NULL)
		return (NULL);
	// top_ways = top_way(all_ways);
	return (top_ways);
}

void	farm_error(int error)
{
	ft_printf("ERROR\n");
	error = 0;
}
