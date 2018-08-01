/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_ways.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:59:53 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/30 14:59:55 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../headers/lem_in.h"

void	add_way_by_increasing_length(t_way **ways, t_way **add_it)
{
	t_way *before;
	t_way *after;

	if (*add_it == NULL)
		return ;
	if (*ways == NULL || (*add_it)->length < (*ways)->length)
	{
		(*add_it)->next = *ways;
		*ways = *add_it;
		return ;
	}
	before = *ways;
	while (before->next != NULL && before->next->length < (*add_it)->length)
		before = before->next;
	after = before->next;
	before->next = *add_it;
	before->next->next = after;
}

void	set_ways_id_and_n_all_ways(t_farm *farm)
{
	t_way *all_ways_head;
	int id;

	id = 1;
	all_ways_head = farm->all_ways;
	all_ways_head = all_ways_head->next;
	while (all_ways_head != NULL)
	{
		if (all_ways_head->next == NULL)
			farm->n_all_ways = id;
		all_ways_head->id = id;
		id++;
		all_ways_head = all_ways_head->next;
	}
}

void	update_top(t_top *top,  t_way **cur_top, int cur_n_ids, int cur_steps)//witout_ants
{
	int i;

	if (top->way_arr != NULL)
		free_way_arr(&top->way_arr, top->size);
	top->size = cur_n_ids;
	top->steps = cur_steps;
	top->way_arr = (t_way **)malloc(sizeof(t_way *) * top->size);
	i = 0;
	while (i < top->size)
	{
		top->way_arr[i] = cur_top[i];
		i++;
	}
}