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

t_farm	*newfarm(int ants)
{
	t_farm	*farm;

	farm = (t_farm*)malloc(sizeof(t_farm));
	if (farm != NULL)
	{
		farm->ants = ants;
		farm->rooms = 0;
		farm->start = 0;
		farm->end = 0;
		farm->map = 0;
	}
	return(farm);
}

int	number_of_ants(t_farm **farm)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	if (check_data(CHECK_N_OF_ANTS, line) == -1)
	{
		ft_strdel(&line);
		return (-1);
	}
	*farm = newfarm(ft_atoi(line));
	ft_strdel(&line);
	return (0);
}

int	set_the_rooms(t_farm **farm)
{
	int check;
	char *line;

	check = 0;
	line = NULL;
	get_next_line(0, &line);
	while ((check = check_data(CHECK_THE_ROOMS, line)) != 0)
	{
		get_next_line(0, &line);
		if(check == -1)
			break ;
	}
	while ()
	return (check);
}