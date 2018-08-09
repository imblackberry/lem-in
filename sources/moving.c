/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 13:18:36 by vblokha           #+#    #+#             */
/*   Updated: 2018/08/09 13:18:37 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

int		step_moving(t_top *top)
{
	int i;

	i = 0;
	while (i < top->size)
	{
		moving_in_each_way(top->way_arr[i], i, top->ants_arr[i]);
		i++;
	}
	return (0);
}

void	moving_in_each_way(t_way *way, int i_way, int ants)
{
	int i;

	i = 0;
	while (i < way->length)
	{
		if (way->ants_moving[i] > 0)
		{
			if (ants <= way->ants_moving[i])
				way->ants_moving[i] = -1;
			else
				way->ants_moving[i] += i_way + way->length;
		}		
		else if (way->ants_moving[i] != -1)
		{
			way->ants_moving[i] = i_way + 1;

		// int k = 0;
		// 	ft_printf("WAY[%d] = ", i_way);
		// while (k < way->length)
		// {
		// 	ft_printf("{%d}", way->ants_moving[k]);
		// 	k++;
		// }
		// ft_printf("\n");

			break ;
		}
		
		
		// int k = 0;
		// 	ft_printf("WAY[%d] = ", i_way);
		// while (k < way->length)
		// {
		// 	ft_printf("{%d}", way->ants_moving[k]);
		// 	k++;
		// }
		// ft_printf("\n");
		i++;		
	}
}

void show_step_moving(t_top *top, t_roomslst *roomslst)
{
	int i;

	i = 0;
	while (i < top->size)
	{
		show_each_way_moving(top->way_arr[i], roomslst);
		i++;
	}
}

void	show_each_way_moving(t_way *way, t_roomslst *roomslst)
{
	int i;
	int j;
	t_roomslst *room;


	i = 0;
	while (i < way->length)
	{
		j = i + 1;
		room = search_room_by_id(roomslst, way->room_way[j]);
		if (way->ants_moving[i] > 0)
			ft_printf("L%d-%s ", way->ants_moving[i], room->name);
		i++;
	}
}