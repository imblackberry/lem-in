/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 12:00:59 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/03 12:00:59 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

int		main()
{
	t_farm *farm;
	int error;

	farm = NULL;
	if ((error = read_and_set(&farm)) < 0)
	{
		farm_error(error);
		return (0);
	}
	// analize(farm);
	// free_farm(&farm);
	return (0);
}

int	read_and_set(t_farm **farm)
{
	if (set_number_of_ants(farm) == -1)
		return (ANTS_ERROR);
	if (set_the_rooms(farm) == -1)
		return (ROOM_ERROR);
	// if (set_the_links(farm) == 1)
	// 	return (1)
	return (0);
}

void	free_farm(t_farm **farm)
{
	if (*farm == NULL || farm == NULL)
		return ;
	free(*farm);
}

void	farm_error(int error)
{
	ft_printf("ERROR\n");
	error = 0;
}

int add_next_line_to_file(char *file, char *line)
{
	char *newline;

	newline = ft_strdup("\n");
	if (file == NULL)
		file = ft_strdup(line);
	else
		ft_join_free(&file, line);
	ft_printf("FILE = %s\n", file);
	ft_strdel(&line);
	ft_strdel(&newline);
	return (0);
}