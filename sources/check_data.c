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

int		check_data(int n, char *line)
{
	int ret;

	ret = 0;
	if (line[0] == '#' && ft_strcmp(line, "##start") == 0 && ft_strcmp(line, "##end") == 0)
		ret = 1;
	else if (n == CHECK_N_OF_ANTS)
		ret = check_number_of_ants(line);
	else if (n == CHECK_THE_ROOMS)
		ret = check_the_rooms(line);
	// else if (n == CHECK_THE_LINKS)
	// 	ret = check_the_links(line);
	else
		ret = -1;
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

int check_the_rooms(char *line)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	ret = check_start_or_end_room(line);
	if (line[i] == 'L' || line[i] == '#')
		return (-1);
	while (line[i] != ' ')
		i++;
	while (ft_isdigit(line[i] != 0))
		i++;
	while (line[i] != ' ')
		i++;
	while (ft_isdigit(line[i] != 0))
		i++;
	if (line[i] == '\0')
		return (1);
	return (-1);
}

int check_start_or_end_room(char *line)
{
	int ret;

	ret = (ft_strcmp(line, "##start") ? 0 : START_ROOM);
	if (ret == 0)
		ret = (ft_strcmp(line, "##end") ? 0 : END_ROOM);
	if (ret != 0)
	{
		ft_strdel(&line);
		if (get_next_line(0, &line) < 0)
			return (-1);
	}
	return (ret);
}
