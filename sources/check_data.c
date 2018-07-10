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
	else if (n == CHECK_ROOMS)
		ret = check_rooms(line);
	else if (n == CHECK_LINKS)
		ret = check_links(line);
	else
		ret = -1;
    

    if (ret > 0)
	    ft_printf("\033[32;1mNORM\n\x1B[0m");
    else
	    ft_printf("\033[34;1m%s\n\x1B[0m", line);
	return (ret);
}

int		check_number_of_ants(char *line)
{
	int i;

	i = 0;
	while (ft_isdigit(line[i]) != 0)
		i++;
	if (line[i] == '\0' && ft_atoi(line) > 0)
		return (1);
	else
		return (-1);
}

int check_rooms(char *line)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	if ((ret = check_start_or_end_room(&line)) < 0)
		return (-1);
	if ((i = check_rooms_name(line)) < 0)
		return (-1);
	if (check_rooms_coordinate(line + i) < 0)
		return (-1);
	return (ret);
}
/* ************************************************************************** */
int check_links(char *line)
{
	int i;
    int hyphen;

	i = 0;
    hyphen = 0;
    while (line[i])
    {
        if (line[i] == '-')
            hyphen++;
        if (hyphen > 1)
            return (-1);
        i++;
    }
    if (hyphen == 1)
    	return (1);
    return (0);
}
