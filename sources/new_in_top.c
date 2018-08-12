/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_in_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 13:25:17 by vblokha           #+#    #+#             */
/*   Updated: 2018/08/09 13:25:19 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

t_top *new_top()
{
	t_top *top;

	top = (t_top*)malloc(sizeof(t_top));
	if (top == NULL)
		return (NULL);
	top->steps = 0;
	top->ants_arr = NULL;
	top->way_arr = NULL;
	top->size = 0;
	return (top);
}

int ants_to_top(t_top *top, int ants)
{
	int step;
	int i;

	i = 0;
	top->ants_arr = ft_memalloc(sizeof(int) * top->size);
	step = top->way_arr[0]->length;
	i = 0;
	while (step <= top->steps)
	{
		while (i + 1 < top->size && step == top->way_arr[i + 1]->length)
			i++;
		fill_ants_to_top(top->ants_arr, i, &ants);
		step++;
	}
	return (1);
}

void	fill_ants_to_top(int *ants_arr, int i, int *ants)
{
	int j;

	j = 0;
	while (j <= i && *ants > 0)
	{
		ants_arr[j]++;
		(*ants)--;
		j++;
	}
}

// ---
//  ---
// ----

int		set_ants_moving_arr(int size, t_way **way_arr)
{
	int i;

	i = 0;
	while (i < size)
	{
		way_arr[i]->ants_moving = ft_memalloc(sizeof(int) * way_arr[i]->length);
		if (way_arr[i]->ants_moving == 0)
			return (-1);
		i++;
	}
	return (1);
}