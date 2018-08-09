/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:47:08 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/19 18:47:09 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

t_roomslst	*search_room_by_id(t_roomslst *roomslst, int id)
{
	if (roomslst == NULL || id < 0)
		return (NULL);
	while (roomslst != NULL)
	{
		if (roomslst->id == id)
			return (roomslst);
		roomslst = roomslst->next;
	}
	return (NULL);
}

int room_exist(char *name, t_roomslst *roomslst)
{
	while (roomslst != NULL)
	{
		if (ft_strcmp(roomslst->name, name) == 0)
			return (1);
		roomslst = roomslst->next;
	}
	return (0);
}

int	room_way_length(int *room_way)
{
	int i;

	i = 0;
	while(room_way[i] != -1)
		i++;
	return (i);
}

t_way *way_before_this_length(t_way *ways, int length)
{
	while (ways != NULL && ways->length < length)
		ways = ways->next;
	return (ways);
}

t_way	*search_way_by_id(t_way *all_ways, int id)
{
	while (all_ways != NULL)
	{
		if (all_ways->id == id)
			return (all_ways);
		all_ways = all_ways->next;
	}
	return (NULL);
}