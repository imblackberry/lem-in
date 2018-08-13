/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:51:45 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/18 19:51:50 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

int		check_data(int n, char *line)
{
	int ret;

	ret = 0;
	if (line == NULL || line[0] == '\0')
		return (-1);
	if (line[0] == '#' &&
		ft_strcmp(line, "##start") != 0 &&
		ft_strcmp(line, "##end") != 0)
		ret = IGNORE_LINE;
	else if (n == CHECK_N_OF_ANTS)
		ret = check_number_of_ants(line);
	else if (n == CHECK_ROOMS)
		ret = check_rooms(line);
	else if (n == CHECK_LINKS)
		ret = check_links(line);
	else
		ret = -1;
	return (ret);
}

int		check_number_of_ants(char *line)
{
	int i;
	int ants;

	i = 0;
	while (ft_isdigit(line[i]) != 0)
		i++;
	ants = ft_atoi(line);
	if (line[i] == '\0' &&
		ants > 0 &&
		line[0] != '0' &&
		ants <= MAX_INT)
		return (1);
	return (-1);
}

int		check_rooms(char *line)
{
	int ret;
	int i;

	if (line == NULL || line[0] == '\0')
		return (-1);
	ret = 1;
	i = 0;
	if ((ret = check_start_or_end_room(&line)) > 1)
		return (ret);
	else if ((i = check_rooms_name(line)) < 0 ||
			check_rooms_coordinate(line + i) < 0)
		return (-1);
	return (ret);
}

int		check_links(char *line)
{
	char *start;
	char *end;

	if (line == NULL || line[0] == '\0')
		return (-1);
	start = ft_strchr(line, '-');
	end = ft_strrchr(line, '-');
	if (start == 0 || end == 0 || start != end)
		return (-1);
	return (1);
}
