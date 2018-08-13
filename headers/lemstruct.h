/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemstruct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:31:50 by vblokha           #+#    #+#             */
/*   Updated: 2018/08/13 13:31:52 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMSTRUCT_H
# define LEMSTRUCT_H

typedef struct	s_roomslst
{
	char				*name;
	int					id;
	struct s_roomslst	*next;
}				t_roomslst;

typedef struct	s_way
{
	int				id;
	int				length;
	int				*room_way;
	int				*ants_moving;
	struct s_way	*next;
}				t_way;

typedef struct	s_top
{
	int			steps;
	int			*ants_arr;
	t_way		**way_arr;
	int			size;
}				t_top;

typedef struct	s_farm
{
	char		*file;
	int			ants;
	t_roomslst	*roomslst;
	int			id_start;
	int			id_end;
	int			nodes;
	int			**map;
	t_way		*all_ways;
	int			n_all_ways;
	t_way		**cur_top;
	int			cur_n_ids;
	t_top		*top;
}				t_farm;

#endif
