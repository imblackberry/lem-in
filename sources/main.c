/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 17:01:44 by vblokha           #+#    #+#             */
/*   Updated: 2018/08/13 17:01:46 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

int		main(int ac, char **av)
{
	t_farm	*farm;
	int		error;

	farm = NULL;
	if ((error = read_and_set(&farm)) < 0 || analyze(farm) < 0)
	{
		farm_error(farm);
		system("leaks lem-in");
		return (0);
	}
	show_process(farm, ac, av);
	free_farm(farm);
	system("leaks lem-in");
	return (0);
}
