/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_by_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 18:16:58 by vblokha           #+#    #+#             */
/*   Updated: 2018/08/21 18:17:01 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

int		*program_args(int ac, char **av, int *args)
{
	int i;

	i = 1;
	if ((args = ft_memalloc(sizeof(int) * 5)) == NULL)
		return (NULL);
	while (i < ac)
	{
		if (ft_strcmp("-r", av[i]) == 0)
			args[0] = 1;
		else if (ft_strcmp("-w", av[i]) == 0)
			args[1] = 1;
		else if (ft_strcmp("-top", av[i]) == 0)
			args[2] = 1;
		else if (ft_strcmp("-m", av[i]) == 0)
			args[3] = 1;
		else
		{
			args[4] = 1;
			free(args);
			return (NULL);
		}
		i++;
	}
	return (args);
}

void	show_process(t_farm *farm, int ac, char **av)
{
	int i;
	int *args;
	int m;

	m = 0;
	args = NULL;
	if ((args = program_args(ac, av, args)) == NULL)
	{
		ft_printf("Options:\n-r\t\t\tshow rooms\n-w\t\t\tshow all ways\
		\n-top\t\t\tshow top set\n-m\t\t\tshow moving\n-h\t\t\thelp\n");
		return ;
	}
	ft_printf("%s\n", farm->file);
	i = 0;
	while (args != NULL && i < 5)
	{
		if (args[i] == 1)
			show_by_arg(farm, i, &m);
		i++;
	}
	if (args != NULL)
		free(args);
	ants_moving(farm, m);
}

void	show_by_arg(t_farm *farm, int i, int *m)
{
	if (i == 0)
		showroomslst(farm->roomslst, farm->id_start, farm->id_end);
	else if (i == 1)
		show_ways(farm->all_ways, farm->roomslst);
	else if (i == 2)
		show_top(farm->top, farm->roomslst);
	else if (i == 3)
		*m = 1;
}
