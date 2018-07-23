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

t_way	*set_all_ways(t_farm *farm)
{
	int i;
	t_step *current;
	t_way *all_ways;

	i = 0;
	current = new_step(farm->id_start);
	add_way(&all_ways, current);
	all_ways = search_and_add_way(farm->map,
		farm->id_end - 1, current, all_ways);
	return (all_ways);
}

// way with start!

int		search_and_add_way(int **map, int end, t_step *current, t_way *ways)
{
	t_step *last_step;
	int i;

	last_step = search_last_step(current);
	if (last_step->room->id == end)
	{
		add_way_to_start(&ways, new_way(current)); // new_way() should copy current
		return (1);
	}
	i = 0;
	while (map[last_step->room->id][i] != -1) // map should be -1 terminated
	{
		if (map[last_step->room->id][i] == 1)
		{
			last_step->next = new_step(i + 1); // 'i' is room id; new_step() creates step from room_id
			search_and_add_way(map, end, current, ways);
			free_step(last_step->next);
		}
		i++;
	}
	return (0);
}
