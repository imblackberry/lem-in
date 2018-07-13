/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_level_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 19:38:43 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/08 19:38:44 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

int check_rooms_coordinate(char *line)
{
	int coordinate;
	int i;

	i = 0;
	coordinate = 1;
	while (coordinate <= 2)
	{
		while (ft_isdigit(line[i]) == 1)
			i++;
		if (i != 0)
		{
			if (line[i] == ' ' && coordinate == 1)
				i++;
			else if (coordinate == 1)
				return (-1);
			else if(line[i] == '\0' && coordinate == 2)
				return (1);
		}
		coordinate++;
		line += i;
		i = 0;
	}
	return (-1);
}

int check_rooms_name(char *line)
{
	int i;

	i = 0;
	if (line[i] == 'L' || line[i] == '#')
		return (-1);
	while (line[i] != ' ')
		i++;
	i++;
	return (i > 0 ? i : -1);
}

int check_start_or_end_room(char **line)
{
	int ret;

	ret = (ft_strcmp(*line, "##start") ? 1 : START_ROOM);
	if (ret == 1)
		ret = (ft_strcmp(*line, "##end") ? 1 : END_ROOM);
	if (ret != 1)
	{
		ft_strdel(line);
		if (get_next_line(0, line) < 0)
			return (-1);
	}
	return (ret);
}

int *check_exsisting_two_rooms_id(char *line, t_roomslst *roomslst)
{
    int len_name;
    t_roomslst *room1;
    t_roomslst *room2;

    if ((room1 = search_room_in_link(line, roomslst)) != NULL)
    {
        
        len_name = strlen(room1->name);
        if (line[len_name] == '-')
        {
            line += len_name + 1;
            room2 = search_room_in_link(line, roomslst);
            len_name = strlen(room2->name);
            if (line[len_name] == '\0')
                return (two_link_id(room1->id, room2->id));
        }
    }
    return (NULL);
}

t_roomslst *search_room_in_link(char *line, t_roomslst *roomslst)
{
    while (roomslst != NULL)
    {
        if (strncmp(line, roomslst->name, strlen(roomslst->name)) == 0)
            return (roomslst);
        roomslst = roomslst->next;
    }
    return (NULL);
}