/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_in_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 20:34:15 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/23 20:34:17 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lem_in.h"

void	add_way_to_start(t_way **ways, t_way *add_it)
{
	if (add_it == NULL)
		return ;
	add_it->next = (*ways);
	(*ways) = add_it;
}