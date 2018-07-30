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

int	no_last_way_intersec(t_way **top, t_way *way_now)
{
	if (n_of_ids <= 1)
		return (1);
	i = 0;
	while (i < way_now->length)
	{
		if (room_exist_in_top(way_now->room_way[i], top) == 1)
			return (хрінь);
		i++;
	}
}

int room_exist_in_top(int room_id, t_way **top)
{
	int i;

	i = 0;
	while (top[i] != NULL)
	{
		if (room_exist_in_one_top(room_id, top[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	room_exist_in_one_top(int room_id, t_way *one_top)
{
	int i;

	i = 0;
	while (i < one_top->length)
	{
		if (one_top->room_way[i] == room_id)
			return (1);
		i++;
	}
	return (0);
}