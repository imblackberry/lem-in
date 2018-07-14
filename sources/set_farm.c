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

int	set_number_of_ants(t_farm **farm)
{
	char *line;
	char check;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		return (-1);
	while ((check = check_data(CHECK_N_OF_ANTS, line)) > 0)
	{
		add_next_line_to_file(&(*farm)->file, line);
		if (line[0] != '#')
		{
			(*farm)->ants = ft_atoi(line);
			return (1);
		}
		else
		{
			ft_strdel(&line);
			if (get_next_line(0, &line) < 0)
				return (-1);
		}
		
	}
	return (-1);
}

char	*set_rooms(t_farm **farm)
{
	char *line;
	int id;
    int check;

	id = 1;
	line = NULL;
	if (get_next_line(0, &line) < 0)
		return NULL;
	while ((check = check_data(CHECK_ROOMS, line)) > 0)
	{
        if (check > 1)
            set_start_or_end_room(check, farm, id, &line);
		if (add_each_room(&(*farm)->roomslst, line, id) < 0)
			return NULL;
		showroomslst((*farm)->roomslst);//DELL
		add_next_line_to_file(&(*farm)->file, line);
		if (get_next_line(0, &line) < 0)
			return NULL;
		id++;
	}
    if (check_links(line) != 0)
        return (line);
    ft_strdel(&line);
	return NULL;
}

void    set_start_or_end_room(int check, t_farm **farm, int id, char **line)
{
	ft_strdel(line);
	if (get_next_line(0, line) < 0)
		return ;
    if (check == START_ROOM)
	{
		add_next_line_to_file(&(*farm)->file, "##start");
        (*farm)->id_start = id;
	}
    else
	{
		add_next_line_to_file(&(*farm)->file, "##end");
        (*farm)->id_end = id;
	}
	
}


int     set_links(t_farm **farm, char *line)
{
    int size_map;
    int *two_link_id;

	if ((*farm)->roomslst == NULL)
		return (-1);
	size_map = (*farm)->roomslst->id;
    (*farm)->map = ft_new_double_int_arr(size_map, size_map, 0);
    while (check_data(CHECK_LINKS, line) > 0)
    {
        ft_printf ("IN CIRCLE Line = [%s]\n", line);
        two_link_id = check_exsisting_two_rooms_id(line, (*farm)->roomslst);
		   ft_printf ("HERE\n");
        if (two_link_id == NULL)
            break ;

        (*farm)->map = add_link_to_the_map((*farm)->map, two_link_id);
        free(two_link_id);  //HEE
        show_int_arr((*farm)->map, size_map, size_map);
        add_next_line_to_file(&(*farm)->file, line);
        if (get_next_line(0, &line) < 0)
		    return (-1);   
    }
    ft_strdel(&line);
    return (0);
}