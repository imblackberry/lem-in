/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:15:13 by vblokha           #+#    #+#             */
/*   Updated: 2018/08/01 16:15:14 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

int	no_last_way_intersec(t_way **cur_top, int cur_n_ids, t_way *way_now)
{
	int i;
	
	if (cur_n_ids == 0)
		return (1);
	i = 1;
	while (i < way_now->length)
	{
		if (room_exist_in_current_top(way_now->room_way[i], cur_top) == 1)
			return (0);
		i++;
	}
	return (1);
}

int room_exist_in_current_top(int room_id, t_way **cur_top)
{
	int i;

	i = 1;
	while (cur_top[i] != NULL)
	{
		if (room_exist_in_one_current_top(room_id, cur_top[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	room_exist_in_one_current_top(int room_id, t_way *one_top)
{
	int i;

	i = 1;
	while (i < one_top->length)
	{
		if (one_top->room_way[i] == room_id)
			return (1);
		i++;
	}
	return (0);
}