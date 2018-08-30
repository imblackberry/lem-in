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

void	showroomslst(t_roomslst *roomslst, int id_start, int id_end)
{
	t_roomslst *room;
	t_roomslst *head;

	head = roomslst;
	ft_printf("\t\033[1m\033[37m  ROOMS\n\n");
	while (roomslst != NULL)
	{
		ft_printf("id = [%d]\t name = %s\n", roomslst->id, roomslst->name);
		roomslst = roomslst->next;
	}
	ft_printf("\033[0m");
	room = search_room_by_id(head, id_start);
	ft_printf("\n\033[1m\033[30m\tSTART ROOM\n\nid = [%d]\tname = %s\n\n",
		id_start, room->name);
	room = search_room_by_id(head, id_end);
	ft_printf("\tEND ROOM\n\nid = [%d]\tname = %s\n\033[0m\n",
		id_end, room->name);
}

void	show_room_way(int *room_way, int room_way_length, t_roomslst *roomslst)
{
	int			i;
	t_roomslst	*room;

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
	ft_printf("\t\033[1m\033[36mALL WAYS\n\n");
	while (ways != NULL)
	{
		ft_printf("\tlen = %d\n", ways->length);
		ft_printf("[%d] =\t", ways->id);
		show_room_way(ways->room_way, ways->length, roomslst);
		ways = ways->next;
		ft_printf("\n");
	}
	ft_printf("\033[0m\n");
}

void	show_top(t_top *top, t_roomslst *roomslst)
{
	int i;

	ft_printf("\t\033[32;1mTOP\n\n");
	ft_printf("STEPS = %lld\nSIZE = %d\n", top->steps, top->size);
	i = 0;
	while (i < top->size)
	{
		ft_printf("\tid = %d\n", top->way_arr[i]->id);
		ft_printf("\tlength = %d\n", top->way_arr[i]->length);
		show_room_way(top->way_arr[i]->room_way, top->way_arr[i]->length,
			roomslst);
		i++;
	}
	ft_printf("\n");
	ft_printf("\033[0m\n");
}
