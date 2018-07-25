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
# define IGNORE_LINE 0
# define ANTS_ERROR -1
# define ROOM_ERROR -2
# define LINK_ERROR -3

# define LINK 1

typedef struct s_roomslst
{
	char *name;
	int id;
	struct s_roomslst *next;
}				t_roomslst;

typedef struct s_way
{
	int id;
	int	length;
	int	*room_way;
	struct s_way *next;
}				t_way;

typedef struct s_farm
{
	char *file;
	int ants;
	t_roomslst *roomslst;
	int id_start;
	int id_end;
	int nodes;
	int **map;
	t_way *all_ways;
	t_way *top_ways;

}				t_farm;

// show_me.c
void	show_room_way(int *room_way, int room_way_length);
void	showroomslst(t_roomslst *roomslst); //DELLLLLLL
void    show_int_arr(int **arr, int size_i, int size_j);//DELL
void	show_ways(t_way *ways);

// lem_in.c
int     read_and_set(t_farm **farm);
void	farm_error();
int		analyze(t_farm *farm);

// free_farm.c 

void	free_farm(t_farm *farm);
void	free_roomslst(t_roomslst **roomslst);
void	free_ways(t_way *ways);
// set_farm.c 
int     set_number_of_ants(t_farm **farm);
char    *set_rooms(t_farm **farm);
int     set_links(t_farm **farm, char *line);
int    set_start_or_end_room(int check, t_farm **farm, int id);


// check_level_2.c 
int     check_start_or_end_room(char **line);
int     check_rooms_name(char *line);
int     check_rooms_coordinate(char *line);
int *check_exsisting_two_rooms_id(char *line, t_roomslst *roomslst);
t_roomslst *search_room_in_lst(char *line, t_roomslst *roomslst);

// check_data.c
int		check_data(int n, char *line);
int		check_number_of_ants(char *line);
int     check_rooms(char *line);
int     check_links(char *line);


// new_structs
t_farm	*newfarm(void);
t_roomslst *newroomslst();
void	set_end_of_map(int **arr, int size);
t_way	*new_way(int *room_way, int way_length_now);
int *new_room_way(int start_node, int size);
// adding.c
int     add_each_room(t_roomslst **roomslst, char *line, int id);
void	add_next_line_to_file(char **file, char *line);
int **add_link_to_the_map(int **map, int *two_link_id);
int *two_link_id(int a, int b);
int	free_line_and_replace_gnl(char **line);

// analyze.c
int		set_all_ways(t_farm *farm);
int		search_and_add_way(t_farm *farm, int *room_way_now, int way_length_now);


// searching.c
t_roomslst	*search_room_by_id(t_roomslst *roomslst, int id);
int room_exist(char *name, t_roomslst *roomslst);
int	room_way_length(int *room_way);

// adding_in_lst.c
void	add_way_to_start(t_way **ways, t_way *add_it);


#endif

// Problems:
// 		comments/commands after ##start is OK
// 		integer coordinates is OK