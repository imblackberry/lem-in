/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_structs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:52:53 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/18 19:52:56 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

t_farm		*newfarm(void)
{
	t_farm	*farm;

	farm = (t_farm*)malloc(sizeof(t_farm));
	if (farm != NULL)
	{
		farm->file = NULL;
		farm->ants = 0;
		farm->roomslst = NULL;
		farm->id_start = 0;
		farm->id_end = 0;
		farm->nodes = 0;
		farm->map = 0;
		farm->all_ways = NULL;
		farm->n_all_ways = 0;
		farm->steps = 0;
		farm->top_ways = NULL;
	}
	return (farm);
}

t_roomslst	*newroomslst(void)
{
	t_roomslst *roomslst;

	roomslst = NULL;
	roomslst = (t_roomslst*)malloc(sizeof(t_roomslst));
	if (roomslst != NULL)
	{
		roomslst->id = 0;
		roomslst->name = NULL;
		roomslst->next = NULL;
	}
	return (roomslst);
}

void	set_end_of_map(int **arr, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		arr[size][i] = -1;
		arr[i][size] = -1;
		i++;
	}
}

int *new_filled_start_int_arr(int start_node, int size)
{
	int *room_way;
	int i;

	room_way = (int*)malloc(sizeof(int) * size);
	if (room_way == NULL)
		return (NULL);
	room_way[0] = start_node;
	i = 1;
	while (i < size)
	{
		room_way[i] = -1;
		i++;
	}
	return (room_way);
}

t_way	*new_way(int *room_way, int room_way_length)
{
	t_way *new_way;

	new_way = (t_way*)malloc(sizeof(t_way));
	if (new_way == NULL)
		return (NULL);
	new_way->room_way = room_way;
	new_way->length = room_way_length;
	new_way->next = NULL;
	return (new_way);
}

t_top *new_top()
{
	t_top *top;

	top = (t_top*)malloc(sizeof(t_top));
	if (top == NULL)
		return (NULL);
	top->steps = 0;
	top->ants = NULL;
	top->way_arr = NULL;
	top->size = 0;
	return (top);
}