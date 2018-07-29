/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:02:22 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/29 18:02:23 by vblokha          ###   ########.fr       */
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