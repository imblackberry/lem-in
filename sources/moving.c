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

int		step_moving(t_top *top, int *mov_size, int m)
{
	int i;

	i = 0;
	while (i < top->size)
	{
		moving_in_each_way(top->way_arr[i], i, &top->ants_arr[i], mov_size);
		show_m(top->way_arr[i]->ants_moving, top->way_arr[i]->length, m);
		i++;
	}
	if (m == 1)
		ft_printf("\n\n");
	return (0);
}

void	moving_in_each_way(t_way *way, int i_way, int *ants_i, int *mov_size)
{
	int i;

	i = way->length - 1;
	while (i >= 0)
	{
		if (i > 0)
			way->ants_moving[i] = way->ants_moving[i - 1];
		else
		{
			if (*ants_i <= 0)
				way->ants_moving[i] = -1;
			else if (way->ants_moving[i + 1] == 0)
				way->ants_moving[i] = i_way + 1;
			else
				way->ants_moving[i] += *mov_size;
			if (*ants_i == 0)
				(*mov_size)--;
		}
		i--;
	}
	(*ants_i)--;
}

void	show_step_moving(t_top *top, t_roomslst *roomslst)
{
	t_ll i;

	i = 0;
	while (i < top->size)
	{
		show_each_way_moving(top->way_arr[i], roomslst);
		i++;
	}
	if (top->way_arr[0]->length != 1)
		ft_printf("\n");
}

void	show_each_way_moving(t_way *way, t_roomslst *roomslst)
{
	int			i;
	int			j;
	t_roomslst	*room;

	i = way->length - 1;
	while (i >= 0)
	{
		j = i + 1;
		room = search_room_by_id(roomslst, way->room_way[j]);
		if (way->ants_moving[i] > 0)
			ft_printf("L%d-%s ", way->ants_moving[i], room->name);
		i--;
	}
}

void	show_m(int *ants_moving, int way_length, int m)
{
	int k;

	if (m == 0)
		return ;
	k = 0;
	ft_printf("\n");
	while (k < way_length)
	{
		ft_printf("[%d]", ants_moving[k]);
		k++;
	}
}
