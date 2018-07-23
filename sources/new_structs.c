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
		farm->nodes = 0;
		farm->map = 0;
		farm->top_ways = NULL;
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

void	set_end_of_map(int **arr, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		arr[size][i] = -1;
		arr[i][size] = -1;
		i++;
	}
}

t_step *new_step(int room_id)
{
	t_step *step;

	step = (t_step*)malloc(sizeof(t_step));
	if (step != NULL)
		step->id = room_id;
	return (step);
}

t_way	*new_way(t_step *step)
{
	t_way *new_way;

	new_way = (t_way*)malloc(sizeof(t_way));
	if (new_way == NULL)
		return (NULL);
	new_way->step = step;
	new_way->length = step_length(step);
	return (new_way);
}