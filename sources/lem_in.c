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

	farm = NULL;
	if (read_and_set(&farm) == -1)
	{
		farm_error();
		return (0);
	}
	// analize(farm);
	free_farm(&farm);
	return (0);
}

int	read_and_set(t_farm **farm)
{
	if (set_number_of_ants(farm) == -1)
		return (-1);
	if (set_the_rooms(farm) == -1)
		return (-1);
	// if (set_the_links(farm) == 1)
	// 	return (1)
	return (0);
}

void	free_farm(t_farm **farm)
{
	if (*farm == NULL)
		return (0);
	free(*farm);
}

void	farm_error()
{
	ft_printf("ERROR\n");
}