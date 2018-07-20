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
	if (roomslst == NULL || id < 1)
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

t_way	*search_and_add_way(int **map, int start, int end, int nodes)
{
	int i;
	t_way *ways;
	t_way *searched_way;
	int new_start;
	int size;
	int j;
	i = start;

	while (1)
	{	
		if (i == end)
		{
			ways = add(ways, searched_way);
			search_and_add_way(map, new_start, end, nodes);
		}
		j = 0;
		new_start = i;
		while(j < nodes)
		{
			if (map[i][j] == LINK)
			{
				map[i][j] = new_start;
				map[j][i] = -1;
				i = j;
				break ;
			}
			j++;
		}
	}
	show_int_arr(map, nodes, nodes);
	return (NULL);
}
