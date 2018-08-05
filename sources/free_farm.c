/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_farm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:52:14 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/18 19:52:16 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

void	free_farm(t_farm *farm)
{
	if (farm == NULL)
		return ;
	ft_strdel(&(farm->file));
	free_roomslst(&(farm->roomslst));
	free_ways(farm->all_ways);
	farm->all_ways = NULL;
	free(farm->top->way_arr);
	free(farm->top);
	free(farm);
}

void	free_roomslst(t_roomslst **roomslst)
{
	t_roomslst *tmp;

	if (*roomslst == NULL)
		return ;
	while (*roomslst != NULL)
	{
		tmp = *roomslst;
		*roomslst = (*roomslst)->next;
		ft_strdel(&(tmp->name));
		free(tmp);
	}
}

void	free_ways(t_way *ways)
{
	t_way *tmp;

	if (ways == NULL)
		return ;
	while (ways != NULL)
	{
		tmp = ways;
		ways = ways->next;
		free(tmp->room_way);
		free(tmp);
	}
}

// void free_way_arr(t_way **way_arr, int size)
// {
// 	free(way_arr);
// }
