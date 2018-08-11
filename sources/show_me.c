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
	ft_putstr(farm->file);
	if (ac == 2 && ft_strcmp(av[1], "-f") == 0)
	{
		ft_printf("\n");
		showroomslst(farm->roomslst);
		ft_printf("\n\033[0;33mSTART ROOM id = [%d]\n", farm->id_start);
		ft_printf("END ROOM id = [%d]\n\033[0m\n", farm->id_end);
		show_ways(farm->all_ways, farm->roomslst);
		show_top(farm->top, farm->roomslst);
	}
	av = 0;
}

void show_usage()
{
	ft_printf("HOHOHOH\n");
}

void	showroomslst(t_roomslst *roomslst)
{
	ft_printf("\t\033[0;32mROOMS\n\033[0m");
	while (roomslst != NULL)
	{
		ft_printf("\033[0;32mid = %d\tname = %s\n\033[0m", roomslst->id, roomslst->name);
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
		ft_printf("\t\033[0;35mlen = %d\n", ways->length);
		ft_printf("[%d] =\t", ways->id);
		show_room_way(ways->room_way, ways->length, roomslst);
		ways = ways->next;
		ft_printf("\n\033[0m\n");
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
	ft_printf("TOP\n");
	ft_printf("STEPS = %d\n SIZE = %d\n", top->steps, top->size);
	show_way_arr(top->way_arr, top->size, roomslst);
}

