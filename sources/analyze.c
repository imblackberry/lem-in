/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 16:16:34 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/19 16:16:35 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

int		set_all_ways(t_farm *farm)
{
	int *room_way;

	room_way = new_filled_start_int_arr(farm->id_start, farm->nodes + 1);
	search_and_add_way(farm, room_way, 1);
	if (farm->all_ways == NULL)
	return (-1);
	show_ways(farm->all_ways);
	set_ways_id_and_n_all_ways(farm);
	// ft_free_double_int_arr(&(farm->map));
	free(room_way);
	return (1);
}

int		search_and_add_way(t_farm *farm, int *room_way_now, int way_length_now)
{
	int i;
	int last_id;
	t_way *new_way_;

	last_id = room_way_now[way_length_now - 1];
	if (last_id == farm->id_end)
	{
		show_room_way(room_way_now, way_length_now);
		new_way_ = new_way(ft_intdup(room_way_now, way_length_now), way_length_now);
		add_way_by_increasing_length(&farm->all_ways, &new_way_);	
		return (1);
	}
	i = 0;
	while (farm->map[last_id][i] != -1)
	{
		if (farm->map[last_id][i] == 1 && ft_intposition(room_way_now, i, way_length_now) == -1)
		{
			room_way_now[way_length_now] = i;
			search_and_add_way(farm, room_way_now, way_length_now + 1);
			room_way_now[way_length_now] = -1;
		}
		i++;
	}
	return (0);
}

int top_ways(t_farm *farm)
{
	farm->top_id_arr = new_filled_start_int_arr(0, farm->n_all_ways + 1);
	steps = count_steps(farm->top_id_arr);
	search_top_ways_ids(farm, steps, 0, farm->all_ways);
	return (1);
}

int *search_top_ways_ids(t_farm *farm, int steps, int ants_already_come, t_way *way_now)
{
	int last_id;

	if (перетин )
		return (0);
	if (way_now == NULL || count_steps(ants_already_come, way_now->length) > steps)
	{
		return (1);
	}
	while (way_now != NULL)
	{
		id_arr[перед -1] = ways->id; //[1][2]
		id_arr = search_top_ways_ids(id_arr, steps, ants_already_come, way_now->next);
		way_now = way_now->next;
	}
}