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

	i = 0;
	j = 0;
	arr[1] = arr[1];
	while (i < size_i)
	{
		j = 0;
		ft_printf("\033[0;32marr[%d]", i);
		while (j < size_j)
		{
			ft_printf("\t|%d|", arr[i][j]);
			j++;
		}
		ft_printf("\n\033[0m");
		i++;
	}
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
	showroomslst(farm->roomslst);
	show_int_arr(farm->map, farm->roomslst->id, farm->roomslst->id);
	ft_printf("\033[0;33mSTART ROOM id = [%d]\n", farm->id_start);
	ft_printf("END ROOM id = [%d]\n\033[0m", farm->id_end);	
	// analize(&farm);
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
	if (set_links(farm, after_rooms_line) == 1)
		return (LINK_ERROR);
	return (0);
}

// void	analize(t_farm **farm)
// {
	
// }

void	farm_error(int error)
{
	ft_printf("ERROR\n");
	error = 0;
}
