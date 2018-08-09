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
	{
		ft_free_double_int_arr(&(farm->map));
		return (-1);
	}
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
	farm->top = new_top();
	if (farm->all_ways->length == 1)
	{
		ft_printf("___________TOP____________\n");
		farm->cur_top = ft_memalloc(sizeof(t_way*) * 2);
		farm->cur_top[0] = farm->all_ways;
		update_top(farm->top, farm->cur_top, 1, farm->ants);
	
		show_top(farm->top);
		ft_printf("_______________________________________\n");
	}
	else
	{
		farm->cur_top = ft_memalloc((sizeof(t_way*) * (farm->n_all_ways + 1)));
		search_top(farm, farm->all_ways, 0, 0);
		if (farm->top->steps == 0)
		{
			free(farm->cur_top);
			return (-1);
		}
		
	}
	free(farm->cur_top);
	ants_to_top(farm->top, farm->ants);
	
	return (1);
}

int	search_top(t_farm *farm,  t_way *way_now, int ants_come, int cur_steps)
{
	int ants_come_now;

	if (ants_come >= farm->ants)
		return (0);
	while (way_now != NULL)
	{
		if (no_last_way_intersec(farm->cur_top, farm->cur_n_ids, way_now) == 1)
		{	
			farm->cur_top[farm->cur_n_ids] = way_now;
			farm->cur_n_ids++;
			ants_come_now = ants_come + change_ants_come(farm->cur_top, farm->cur_n_ids);
			cur_steps = way_now->length - 1 + count_steps(ants_come_now, farm->ants, farm->cur_n_ids);
			if (farm->top->steps == 0 || cur_steps < farm->top->steps)
				update_top(farm->top, farm->cur_top, farm->cur_n_ids, cur_steps);
			search_top(farm, way_now->next, ants_come_now, cur_steps);
			farm->cur_n_ids--;
			farm->cur_top[farm->cur_n_ids] = NULL;
		}
		way_now = way_now->next;
	}
	return (0);
}


// 3 5 8
// ---
//  ---
// ----
//   ---
//  ----
//    ---
//   ----
//    ---