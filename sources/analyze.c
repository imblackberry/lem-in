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
	set_ways_id_and_n_all_ways(farm);
	show_ways(farm->all_ways);
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
	farm->top = new_top();
	farm->cur_top = ft_memalloc(farm->n_all_ways + 1);
	// farm->top_ways[0] = farm->all_ways;
	// farm->steps = count_steps(farm->top_ways);
	search_top(farm, farm->all_ways, 0, 0);
	free_way_arr(&farm->cur_top, farm->cur_n_ids);
	return (1);
}

int	search_top(t_farm *farm,  t_way *way_now, int ants_come, int cur_steps)
{
	ft_printf("|||||||||||||||||||||\n");
	show_way_arr(farm->cur_top, farm->cur_n_ids);
	ants_come = change_ants_come(ants_come, farm->cur_top, farm->cur_n_ids, way_now);
	cur_steps = cur_steps + count_steps(ants_come, farm->ants, farm->cur_n_ids);
	if (cur_steps < farm->top->steps)
	{
		update_top(farm->top, farm->cur_top, farm->cur_n_ids, cur_steps);
		show_top(farm->top);
		return (1);
	}
	while (way_now != NULL)
	{
		if (no_last_way_intersec(farm->cur_top, farm->cur_n_ids, way_now) == 1)
		{
			
			farm->cur_top[farm->cur_n_ids] = way_now; //ants already come
			farm->cur_n_ids++;
			if (farm->cur_n_ids == 1)
				cur_steps = way_now->length - 1 + farm->ants;
			if (search_top(farm, way_now->next, ants_come, cur_steps) == 0)
				return (0);
			farm->cur_top[farm->cur_n_ids] = NULL;
			farm->cur_n_ids--;
		}
		way_now = way_now->next;
	}
	return (0);
}

int	change_ants_come(int ants_come, t_way **cur_top, int cur_n_ids, t_way *way_now)
{
	if (cur_n_ids == 0)
		return (0);
	ants_come = ants_come + (way_now->length - cur_top[cur_n_ids - 1]->length) * cur_n_ids;
	return (ants_come);
}

int count_steps(int ants_come, int ants, int cur_n_ids)
{
	int steps;

	if (cur_n_ids == 0)
		return (0);
	ants_come = (ants - ants_come);
	steps =  ants_come / cur_n_ids;
	if  (ants_come % cur_n_ids > 0)
		steps++;
	return (steps);
}
// ants = 7
// [0] l = 3
// ants_come = 3

// 3 < 7 --go on
// [1] l = 3
// [2] l = 5
// ants_come = 3 + (6 - 5) * 2 = 5

// 5 < 7
// [1] l = 2
// [2] l = 5
// [3] l = 6
// ants_come = 5 + ()