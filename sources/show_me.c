/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 11:54:22 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/24 11:54:23 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

void	show_int_arr(int **arr, int size_i, int size_j)
{
	int i;
	int j;

	size_i++;
	size_j++;
	i = 0;
	j = 0;
	arr[1] = arr[1];
	ft_printf("\033[0;32m\t");
	while (j < size_j)
	{
		ft_printf("id[%d]\t", j);
		j++;
	}
	ft_printf("\n");
	while (i < size_i)
	{
		j = 0;
		ft_printf("id[%d]", i);
		while (j < size_j)
		{
			ft_printf("\t|%d|", arr[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("___________________________________________________________________________________________________________________________________\n\033[0m");
}

void	showroomslst(t_roomslst *roomslst)
{
	while (roomslst != NULL)
	{
		ft_printf("\033[0;34mid = %d\tname = %s\n\033[0m", roomslst->id, roomslst->name);
		roomslst = roomslst->next;
	}
}

void	show_room_way(int *room_way, int room_way_length, t_roomslst *roomslst)
{
	int i;
	t_roomslst *room;

	i = 0;
	while (i <= room_way_length)
	{
		room = search_room_by_id(roomslst, room_way[i]);
		if (i == room_way_length)
			ft_printf("%s", room->name);
		else
			ft_printf("%s->", room->name);
		i++;
	}
	ft_printf("\n");
}

void	show_ways(t_way *ways, t_roomslst *roomslst)
{
	while (ways != NULL)
	{
		ft_printf("\tlen = %d\n", ways->length);
		ft_printf("[%d] =\t", ways->id);
		show_room_way(ways->room_way, ways->length, roomslst);
		ways = ways->next;
		ft_printf("\n");
	}
}

void	show_way_arr(t_way **way, int size, t_roomslst *roomslst)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_printf("WAY_ARR\n");
		ft_printf("\t\tid = %d\n", way[i]->id);
		ft_printf("\t\tlength = %d\n", way[i]->length);
		show_room_way(way[i]->room_way, way[i]->length, roomslst);
		i++;
	}
	ft_printf("\n");
}

void	show_top(t_top *top, t_roomslst *roomslst)
{
	ft_printf("TOP\n");  // \x1B[0m
	ft_printf("STEPS = %d\n SIZE = %d\n", top->steps, top->size);
	show_way_arr(top->way_arr, top->size, roomslst);
}

