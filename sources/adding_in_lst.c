/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_in_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 20:34:15 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/23 20:34:17 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

void	add_way_by_increasing_length(t_way **ways, t_way **add_it)
{
	t_way *before;
	t_way *after;

	// ft_printf("__________________________________\n");
	// // show_ways(*ways);
	// show_ways(*add_it);
	// ft_printf("__________________________________\n");
	if (*add_it == NULL)
		return ;
		// show_ways(*ways);
	if (*ways == NULL || (*add_it)->length < (*ways)->length)
	{
		(*add_it)->next = *ways;
		*ways = *add_it;
		return ;
	}
	// ft_printf("----\n");
	before = *ways;
	while (before->next != NULL && before->next->length < (*add_it)->length)
		before = before->next;
	after = before->next;
	before->next = *add_it;
	before->next->next = after;
}
