/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_farm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:08:31 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/03 16:08:32 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

t_farm	*newfarm(int ants)
{
	t_farm	*farm;

	farm = (t_farm*)malloc(sizeof(t_farm));
	if (farm != NULL)
	{
		farm->ants = ants;
		farm->file = NULL;
		farm->roomslst = NULL;
		farm->id_start = 0;
		farm->id_end = 0;
		farm->map = 0;
	}
	return(farm);
}

int	set_number_of_ants(t_farm **farm)
{
	char *line;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		return (-1);
	if (check_data(CHECK_N_OF_ANTS, line) == -1)
	{
		ft_strdel(&line);
		return (-1);
	}
	else
	{
		*farm = newfarm(ft_atoi(line));
		add_next_line_to_file((*farm)->file, line);
	}
	return (0);
}

int	set_the_rooms(t_farm **farm)
{
	char *line;
	int id;

	id = 0;
	line = NULL;
	if (get_next_line(0, &line) < 0)
		return (-1);
	while (check_data(CHECK_THE_ROOMS, line) > 0)
	{
		add_each_room(&(*farm)->roomslst, line, id);
		add_next_line_to_file((*farm)->file, line);
		if (get_next_line(0, &line) < 0)
			return (-1);
		id++;
	}
	ft_printf("FILE = %s\n", (*farm)->file);
	return (1);
}

int ft_chrposition(char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

void	add_each_room(t_roomslst **roomslst, char *line, int id)
{
	while (*roomslst != NULL && (*roomslst)->next != NULL)
		*roomslst = (*roomslst)->next;
	(*roomslst)->next = (t_roomslst*)malloc(sizeof(t_roomslst));
	if (*roomslst != NULL)
	{
		(*roomslst)->id = id;
		(*roomslst)->name = ft_strsub(line, 0, ft_chrposition(line, ' ') + 1);
	}
}