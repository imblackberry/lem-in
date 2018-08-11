/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_farm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:53:06 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/18 19:53:07 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

int		set_number_of_ants(t_farm **farm)
{
	char *line;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		return (-1);
	while ((check_data(CHECK_N_OF_ANTS, line)) >= 0)
	{
		add_next_line_to_file(&(*farm)->file, line);
		if (line[0] != '#')
		{
			(*farm)->ants = ft_atoi(line);
			ft_strdel(&line);
			return (1);
		}
		ft_strdel(&line);
		if (get_next_line(0, &line) < 0)
			return (-1);
	}
	return (-1);
}

char	*set_rooms(t_farm **farm)
{
	char	*line;
	int		id;
	int		check;

	id = 0;
	line = NULL;
	int gnl;
	if ((gnl = get_next_line(0, &line)) < 0)
		return (NULL);
	while ((check = check_data(CHECK_ROOMS, line)) >= 0)
	{
		add_next_line_to_file(&(*farm)->file, line);
		if (check > 1)
		{
			if (set_start_or_end_room(check, farm, id, &line) < 0 ||
			check_data(CHECK_ROOMS, line) <= 0)
				return (NULL);
			continue ;
		}
		else if (check == 1)
		{
			if (add_each_room(&(*farm)->roomslst, line, &id) < 0)
				return (NULL);
		}
		if (free_line_and_replace_gnl(&line) < 0)
			return (NULL);
	}
	if (check_links(line) > 0)
		return (line);
	ft_strdel(&line);
	return (NULL);
}

int		set_start_or_end_room(int check, t_farm **farm, int id, char **line)
{
	if (check == START_ROOM)
		(*farm)->id_start = ((*farm)->id_start == -1) ? id : -2;
	if (check == END_ROOM)
		(*farm)->id_end = ((*farm)->id_end == -1) ? id : -2;
	if ((*farm)->id_start == -2 || (*farm)->id_end == -2)
		return (-1);
	if (free_line_and_replace_gnl(line) < 0)
		return (-1);
	return (1);
}

int		set_links(t_farm **farm, char *line)
{
	int *two_link_id;
	int check;

	if ((*farm)->roomslst == NULL || (*farm)->id_start < 0 || (*farm)->id_end < 0)
		return (-1);
	(*farm)->map = ft_new_double_int_arr((*farm)->nodes + 1, (*farm)->nodes + 1, 0);
	set_end_of_map((*farm)->map, (*farm)->nodes);
	while ((check = check_data(CHECK_LINKS, line)) >= 0)
	{
		add_next_line_to_file(&(*farm)->file, line);
		if (check != IGNORE_LINE)
		{
			two_link_id = check_exsisting_two_rooms_id(line, (*farm)->roomslst);
			if (two_link_id == NULL)
				break ;
			(*farm)->map = add_link_to_the_map((*farm)->map, two_link_id);
			free(two_link_id);
		}
		free_line_and_replace_gnl(&line);
	}
	ft_strdel(&line);
	return (0);
}
