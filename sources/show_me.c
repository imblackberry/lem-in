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

int			*program_args(int ac, char **av, int *args)
{
	int i;

	i = 1;
	if ((args = ft_memalloc(sizeof(int) * 5)) == NULL)
		return (NULL);
	while (i < ac)
	{
		if (ft_strcmp("-r", av[i]) == 0)
			args[0] = 1;
		else if (ft_strcmp("-w", av[i]) == 0)
			args[1] = 1;
		else if (ft_strcmp("-top", av[i]) == 0)
			args[2] = 1;
		else if (ft_strcmp("-m", av[i]) == 0)
			args[3] = 1;
		else
		{
			args[4] = 1;
			free(args);
			ft_printf("%s", USAGE);
			return (NULL);
		}
		i++;
	}
	return (args);
}

void	show_process(t_farm *farm, int ac, char **av)
{
	int i;
	int *args;

	_m = 0;
	args = NULL;
	if ((args = program_args(ac, av, args)) == NULL)
		return ;
	ft_printf("%s\n", farm->file);
	i = 0;
	while (args != NULL && i < 5)
	{
		if (args[i] == 1)
		{
			if (i == 0)
				showroomslst(farm->roomslst, farm->id_start, farm->id_end);
			else if (i == 1)
				show_ways(farm->all_ways, farm->roomslst);
			else if (i == 2)
				show_top(farm->top, farm->roomslst);
			else if (i == 3)
				_m = 1;
		}
		i++;
	}
	free(args);
	ants_moving(farm);
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
	ft_printf("STEPS = %d\nSIZE = %d\n", top->steps, top->size);
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
