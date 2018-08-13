/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_farm_level_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:12:16 by vblokha           #+#    #+#             */
/*   Updated: 2018/08/13 16:12:17 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

int	set_each_link(char *line, t_farm *farm, int check)
{
	int *two_link_id;

	if (check != IGNORE_LINE)
	{
		two_link_id = check_exsisting_two_rooms_id(line, farm->roomslst);
		if (two_link_id == NULL)
		{
			clear_last_file_line(farm->file);
			return (-1);
		}
		farm->map = add_link_to_the_map(farm->map, two_link_id);
		free(two_link_id);
	}
	return (1);
}

int	set_each_room(char **line, t_farm *farm, int *id, int check)
{
	if (check > 1)
	{
		if (set_start_or_end_room(check, farm, *id, line) < 0 ||
			check_rooms(*line) < 0)
			return (ERROR);
	}
	else if (check == 1)
	{
		if (add_each_room(&farm->roomslst, *line, id) < 0)
			return (ERROR);
	}
	return (1);
}
