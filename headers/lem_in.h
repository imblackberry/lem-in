/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:58:13 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/03 11:58:13 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../ft_printf/headers/ft_printf.h"
# define CHECK_N_OF_ANTS 1
# define CHECK_THE_ROOMS 2
# define CHECK_THE_LINKS 3

typedef struct s_roomslst
{
	char *name;
	int id;
}				t_roomslst;

typedef struct s_farm
{
	int ants;
	t_roomslst *roomslst;
	int rooms;
	int start;
	int end;
	int **map;
}				t_farm;

int	read_and_set(t_farm **farm);
int	set_number_of_ants(t_farm **farm);
t_farm	*newfarm(int ants);
void	farm_error();

#endif
