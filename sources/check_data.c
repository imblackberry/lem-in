/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 15:44:17 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/03 15:44:18 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

int		check_data(int n, char *line, t_roomslst *roomslst)
{
	int ret;

	ret = 0;
	if (line[0] == '#' && ft_strcmp(line, "##start") == 0 && ft_strcmp(line, "##end") == 0)
		ret = 1;
	else if (n == CHECK_N_OF_ANTS)
		ret = check_number_of_ants(line);
	else if (n == CHECK_ROOMS)
		ret = check_rooms(line);
	else if (n == CHECK_LINKS)
		ret = check_links(line);
	else
		ret = -1;
	ft_printf("\033[32;1mNORM\n\x1B[0m");
	return (ret);
}

int		check_number_of_ants(char *line)
{
	int i;

	i = 0;
	while (ft_isdigit(line[i]) != 0)
		i++;
	if (line[i] == '\0')
		return (0);
	else
		return (-1);
}

int check_rooms(char *line)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	if (check_start_or_end_room(&line) < 0)
		return (-1);
	if ((i = check_rooms_name(line)) < 0)
		return (-1);
	if (check_rooms_coordinate(line + i) < 0)
		return (-1);
	return (1);
}
/* ************************************************************************** */
int check_links(char *line, t_roomslst *roomslst)
{
	int i;

	i = 0;
	i = after_existing_room(line, roomslst);
	if (i > 1 && line[i] == '-')
		i++;
	else
		return (-1);
	line += i;
	i = after_existing_room(line, roomslst);
	if (i > 1 && line[i] == '\0')
		return (1);
	return (-1);
}

int	after_existing_room(char *line, t_roomslst *roomslst)
{
	char *line_name;
	int i;

	i = 0;
	i = ft_chrposition(line, '-');
	line_name = ft_strsub(line, 0, i);
	while (roomslst != NULL && ft_strcmp(roomslst->name, line_name) != 0)
		roomslst = roomslst->next;
	if (roomslst == NULL)
	{
		ft_strdel(&line_name);
		return (1);
	}
	ft_strdel(&line_name);
	return (-1);
}