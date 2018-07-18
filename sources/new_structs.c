/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_structs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:52:53 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/18 19:52:56 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

t_farm		*newfarm(void)
{
	t_farm	*farm;

	farm = (t_farm*)malloc(sizeof(t_farm));
	if (farm != NULL)
	{
		farm->ants = 0;
		farm->file = NULL;
		farm->roomslst = NULL;
		farm->id_start = 0;
		farm->id_end = 0;
		farm->map = 0;
	}
	return (farm);
}

t_roomslst	*newroomslst(void)
{
	t_roomslst *roomslst;

	roomslst = NULL;
	roomslst = (t_roomslst*)malloc(sizeof(t_roomslst));
	if (roomslst != NULL)
	{
		roomslst->id = 0;
		roomslst->name = NULL;
		roomslst->next = NULL;
	}
	return (roomslst);
}
