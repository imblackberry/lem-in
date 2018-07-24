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

int	set_all_ways(t_farm *farm)
{
	int *room_way;

	room_way = new_room_way(farm->id_start, farm->nodes + 1);
	// room_way[0][2]...
	farm->all_ways = new_way(room_way);
	search_and_add_way(farm, room_way, 1);
	show_ways(farm->all_ways);
	return (1);
}

// way with start!

int		search_and_add_way(t_farm *farm, int *room_way_now, int way_length_now)
{
	int i;
	int last_id;

	last_id = room_way_now[way_length_now - 1];
	// show_room_way(room_way_now);
	if (last_id == farm->id_end)
	{
		show_room_way(room_way_now);
		// add_way_to_start(&farm->all_ways, new_way(ft_intdup(room_way_now, way_length_now)));
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
