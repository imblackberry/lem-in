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
	ft_free_double_int_arr(&(farm->map));
	free_ways(farm->all_ways);
	farm->all_ways = NULL;
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
		tmp = ways->next;
		free(ways->room_way);
		free(ways);
		ways = tmp;
	}
}

void free_way_arr(t_way ***way_arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(way_arr[0][i]);
		way_arr[0] = NULL;
		i++;
	}
	free(way_arr[0]);
	way_arr = NULL;
}
