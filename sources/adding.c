/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:51:29 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/18 19:51:34 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

int		add_each_room(t_roomslst **roomslst, char *line, int *id)
{
	t_roomslst *new;
	char *name;

	new = NULL;
	name = ft_strsub(line, 0, ft_chrposition(line, ' '));
	if (room_exist(name, *roomslst) == 1)
		return (-1);
	new = newroomslst();
	if (new != NULL)
	{
		new->id = *id;
		new->name = name;
	}
	if (*roomslst != NULL)
		new->next = *roomslst;
	*roomslst = new;
	(*id)++;
	return (1);
}

void	add_next_line_to_file(char **file, char *line)
{
	char *newline;

	newline = ft_strdup("\n");
	if (*file == NULL)
		*file = ft_strdup(line);
	else
		ft_join_free(file, line);
	ft_join_free(file, newline);
	ft_strdel(&newline);
}

int		**add_link_to_the_map(int **map, int *two_link_id)
{
	int i;
	int j;

	i = 0[two_link_id];
	j = 1[two_link_id];
	map[i][j] = 1;
	map[j][i] = 1;
	return (map);
}

int		*two_link_id(int a, int b)
{
	int *two_link_id;

	two_link_id = (int*)malloc(sizeof(int) * 2);
	two_link_id[0] = a;
	two_link_id[1] = b;
	return (two_link_id);
}

int		free_line_and_replace_gnl(char **line)
{
	ft_strdel(line);
	if (get_next_line(0, line) < 0)
		return (-1);
	return (1);
}