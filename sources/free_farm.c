/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_farm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:52:14 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/18 19:52:16 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

void	free_farm(t_farm *farm)
{
	ft_free_double_int_arr(&(farm->map));
	ft_strdel(&(farm->file));
	free_roomslst(&(farm->roomslst));
	if (farm == NULL)
		return ;
	free(farm);
}

void	free_roomslst(t_roomslst **roomslst)
{
	t_roomslst *tmp;

	if (*roomslst == NULL)
		return ;
	while (*roomslst != NULL)
	{
		tmp = *roomslst;
		*roomslst = (*roomslst)->next;
		ft_strdel(&(tmp->name));
		free(tmp);
	}
}

