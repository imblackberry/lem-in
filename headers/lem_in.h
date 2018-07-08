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
# define CHECK_ROOMS 2
# define CHECK_LINKS 3
# define START_ROOM 2
# define END_ROOM 3
# define NORM 1
# define ANTS_ERROR -1
# define ROOM_ERROR -2
# define LINK_ERROR -3

typedef struct s_roomslst
{
	char *name;
	int id;
	struct s_roomslst *next;
}				t_roomslst;

typedef struct s_farm
{
	char *file;
	int ants;
	t_roomslst *roomslst;
	int n_of_rooms;
	int id_start;
	int id_end;
	int **map;
}				t_farm;
void	showroomslst(t_roomslst *roomslst); //DELLLLLLL
int	read_and_set(t_farm **farm);
int	set_number_of_ants(t_farm **farm);
t_farm	*newfarm(int ants);
void	farm_error();
void	free_farm(t_farm **farm);
void	add_next_line_to_file(char **file, char *line);
int		check_data(int n, char *line, t_roomslst *roomslst);
int		check_number_of_ants(char *line);
int check_rooms(char *line);
int check_start_or_end_room(char **line);
int	set_rooms(t_farm **farm);
int ft_chrposition(char *str, int c);
int	add_each_room(t_roomslst **roomslst, char *line, int id);
int check_rooms_name(char *line);
int check_rooms_coordinate(char *line);
int ft_chrposition(char *str, int c);

#endif
