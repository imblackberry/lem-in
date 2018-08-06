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
	if (farm->all_ways->length == 1)
		update_top(farm->top, farm->cur_top, farm->cur_n_ids, 1);
	else
	{
		farm->cur_top = ft_memalloc((sizeof(t_way*) * (farm->n_all_ways + 1)));
		search_top(farm, farm->all_ways, 0, 0);
		if (farm->top->steps == 0)
		{
			free(farm->cur_top);
			return (-1);
		}
		free(farm->cur_top);
		ft_printf("___________TOP____________\n");
		show_top(farm->top);
		ft_printf("_______________________________________\n");
	}
	return (1);
}

int	search_top(t_farm *farm,  t_way *way_now, int ants_come, int cur_steps)
{
	int ants_come_now;

	while (way_now != NULL)
	{
				ft_printf("****************************\n");
					show_way_arr(farm->cur_top, farm->cur_n_ids);
					ft_printf("WAY_NOW\nid = %d \n", way_now->id);
					show_room_way(way_now->room_way, way_now->length);
					ft_printf("*****************************\n");
		if (no_last_way_intersec(farm->cur_top, farm->cur_n_ids, way_now) == 1)
		{
					
			farm->cur_top[farm->cur_n_ids] = way_now;
			farm->cur_n_ids++;
			ants_come_now = change_ants_come(ants_come, farm->cur_top, farm->cur_n_ids);
					ft_printf(" ANTS_COME = %d\n", ants_come_now);
			cur_steps = way_now->length - 1 + count_steps(ants_come_now, farm->ants, farm->cur_n_ids);
					ft_printf("STEPS = %d\n", cur_steps);
			if (farm->top->steps == 0 || cur_steps < farm->top->steps)
			{
				update_top(farm->top, farm->cur_top, farm->cur_n_ids, cur_steps);
				ft_printf("___________TOP____________\n");
				show_top(farm->top);
				ft_printf("_______________________________________\n");
			}
			search_top(farm, way_now->next, ants_come_now, cur_steps);
			farm->cur_top[farm->cur_n_ids] = NULL;
			farm->cur_n_ids--;
		}

		way_now = way_now->next;
	}
	return (0);
}

int	change_ants_come(int ants_come, t_way **cur_top, int cur_n_ids)
{
	ft_printf("\t\t\t\tIN FUNCTION ANTS_COME = %d ", ants_come);
	if (cur_n_ids <= 1)
		return (0);
	ants_come = ants_come + (cur_top[cur_n_ids - 1]->length - cur_top[cur_n_ids - 2]->length) * (cur_n_ids - 1) ;
	ft_printf(" + (%d - %d) * %d = %d\n", cur_top[cur_n_ids - 1]->length, cur_top[cur_n_ids - 2]->length, cur_n_ids - 1,  ants_come);
	ft_printf("\t\t\t\tIN FUNCTION ANTS_COME = %d\n", ants_come);
	return (ants_come);
}
// how much ants has gone for way_now_length-1 steps

int count_steps(int ants_come, int ants, int cur_n_ids)
{
	int steps;

	if (cur_n_ids == 1)
		return (ants);
	ants_come = (ants - ants_come);
	steps =  ants_come / cur_n_ids;
	if  (ants_come % cur_n_ids > 0)
	{
		ft_printf("\t\t\t\tIN FUNCTION STEPS + 1");
		steps++;
	}
	ft_printf("\t\t\t\tIN FUNCTION STEPS = %d / %d =%d ", ants_come, cur_n_ids, steps);
	return (steps);
}

// 1234567
// -----
// -----
//  -----
//  -----
//   -----
//   -----
//    -----
//    -----
// --------
//     -----
//     -----
//  --------
//      -----
//      -----
//   --------
//       -----
//       -----
//    --------
//        -----
//        -----
//     --------
//         -----
//         -----
//      --------
//          -----
//          -----
//       --------
//           -----
//           -----