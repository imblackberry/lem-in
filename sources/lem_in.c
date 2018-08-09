/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:52:26 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/18 19:52:28 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

int	read_and_set(t_farm **farm)
{
	char *after_rooms_line;

	*farm = newfarm();
	if (set_number_of_ants(farm) == -1)
		return (ANTS_ERROR);
	if ((after_rooms_line = set_rooms(farm)) == NULL)
		return (ROOM_ERROR);
	(*farm)->nodes = (*farm)->roomslst->id + 1;
	if (set_links(farm, after_rooms_line) < 0)
		return (LINK_ERROR);
	return (0);
}

int	analyze(t_farm *farm)
{
	int top_way;

	if (set_all_ways(farm) < 0)
		return (-1);
	top_way = top_ways(farm);
	return (1);
}

void	farm_error(int error)
{
	ft_printf("ERROR\n");
	error = 0;
}

int        ants_moving(t_farm *farm)
{
	int step;

	if (set_ants_moving_arr(farm->top->size, farm->top->way_arr) < 0)
		return (-1);
	step = 0;
	while (step < farm->top->steps)
	{
		
		if (step_moving(farm->top) < 0)
			return (-1);
		show_step_moving(farm->top, farm->roomslst);
		if (farm->top->way_arr[0]->length != 1)
			ft_printf("\n");
		step++;
	}
	if (farm->top->way_arr[0]->length == 1)
		ft_printf("\n");
	return (1);
}