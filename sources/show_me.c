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

void	show_process(t_farm *farm, int ac, char **av)
{
	if (ac == 1)
	{
		ft_printf("%s\n", farm->file);
		ants_moving(farm);
	}
	else if (ac == 2 && ft_strcmp(av[1], "-f") == 0)
	{
		ft_printf("%s\n", farm->file);
		ft_printf("\n");
		showroomslst(farm->roomslst, farm->id_start, farm->id_end);
		show_ways(farm->all_ways, farm->roomslst);
		show_top(farm->top, farm->roomslst);
		ants_moving(farm);
	}
	else
		show_usage();
	av = 0;
}

void show_usage()
{
	ft_printf("number_of_ants\nthe_rooms\nthe_links\n");
}

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
	ft_printf("\n\033[1m\033[30m\tSTART ROOM\n\nid = [%d]\tname = %s\n\n", id_start, room->name);
		room = search_room_by_id(head, id_end);
	ft_printf("\tEND ROOM\n\nid = [%d]\tname = %s\n\033[0m\n", id_end, room->name);
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

void	show_way_arr(t_way **way, int size, t_roomslst *roomslst)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_printf("\tid = %d\n", way[i]->id);
		ft_printf("\tlength = %d\n", way[i]->length);
		show_room_way(way[i]->room_way, way[i]->length, roomslst);
		i++;
	}
	ft_printf("\n");
}

void	show_top(t_top *top, t_roomslst *roomslst)
{
	ft_printf("\t\033[32;1mTOP\n\n");
	ft_printf("STEPS = %d\nSIZE = %d\n", top->steps, top->size);
	show_way_arr(top->way_arr, top->size, roomslst);
	ft_printf("\033[0m\n");
}

