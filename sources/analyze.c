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
	ft_free_double_int_arr(&(farm->map));
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
	i = 0;//&&
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
	farm->top = ft_memalloc(farm->n_all_ways + 1);
	// farm->top_ways[0] = farm->all_ways;
	// farm->steps = count_steps(farm->top_ways);
	search_top(farm, farm->all_ways, 0, 0);
	return (1);
}

int	search_top(t_farm *farm,  t_way *way_now, int ants_come, int n_of_ids)
{
	ants_come = change_ants_come(ants_come, farm->top, n_of_ids, way_now->next);
	if (ants_come > ants)
		return (result); //stop
	if (n_of_ids > тих, що були)
		set top and go on
	while (way_now != NULL)
	{
		if (no_last_way_intersec(farm->top,  way_now) == 1)
		{
			top[n_of_ids] = way_now; //ants already come
			
			if (search_top_ways_ids(farm, way_now->next, ants_come, n_of_ids + 1) == 1)
				return (1);
			top[n_of_ids] = NULL;
		}
		way_now = way_now->next;
	}
	return (1);
}

int	change_ants_come(int ants_come, t_way **top, int n_of_ids, t_way *way_next)
{
	ants_come = ants_come + (way_next->length - top[n_of_ids - 1]->length) * n_of_ids;
}
// ants = 7
// [1] l = 2
// ants_come = 3

// 3 < 7 --go on
// [1] l = 2
// [2] l = 5
// ants_come = 3 + (6 - 5) * 2 = 5

// 5 < 7
// [1] l = 2
// [2] l = 5
// [3] l = 6
// ants_come = 5 + ()