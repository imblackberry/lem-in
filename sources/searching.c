/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:47:08 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/19 18:47:09 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

t_step *search_last_step(t_step *step)
{
	while (step != NULL || step->next != NULL)
		step = step->next;
	return (step);
}

t_roomslst	*search_room_by_id(t_roomslst *roomslst, int id)
{
	if (roomslst == NULL || id < 1)
		return (NULL);
	while (roomslst != NULL)
	{
		if (roomslst->id == id)
			return (roomslst);
		roomslst = roomslst->next;
	}
	return (NULL);
}

int room_exist(char *name, t_roomslst *roomslst)
{
	while (roomslst != NULL)
	{
		if (ft_strcmp(roomslst->name, name) == 0)
			return (1);
		roomslst = roomslst->next;
	}
	return (0);
}

