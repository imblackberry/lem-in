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
# define MAX_INT 2147483647
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
	int *ants_moving;
	struct s_way *next;
}				t_way;

typedef struct s_top
{
	int steps;
	int *ants_arr;
	t_way **way_arr;
	int size;
}				t_top;

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
	int n_all_ways;
	t_way **cur_top;
	int cur_n_ids;
	t_top *top;
}				t_farm;

// show_me.c
void	show_process(t_farm *farm, int ac, char **av);
void	show_room_way(int *room_way, int room_way_length, t_roomslst *roomslst);
void	showroomslst(t_roomslst *roomslst, int id_start, int id_end);
void    show_int_arr(int **arr, int size_i, int size_j);//DELL
void	show_ways(t_way *ways, t_roomslst *roomslst);
void	show_way_arr(t_way **way, int size, t_roomslst *roomslst);
void	show_top(t_top *top, t_roomslst *roomslst);
void	show_usage();
// main.c

// lem_in.c
int			read_and_set(t_farm **farm);
void	farm_error( t_farm *farm);
int			analyze(t_farm *farm);
int        ants_moving(t_farm *farm);

// free_farm.c 
void		free_farm(t_farm *farm);
void		free_roomslst(t_roomslst **roomslst);
void		free_ways(t_way *ways);
void	free_top(t_top *top);

// void		free_way_arr(t_way **way_arr, int size);

// set_farm.c 
int			set_number_of_ants(t_farm *farm);
char		*set_rooms(t_farm *farm);
int			set_links(t_farm *farm, char *line);
int			set_start_or_end_room(int check, t_farm *farm, int id, char **line);


// check_level_2.c 
int     	check_start_or_end_room(char **line);
int     	check_rooms_name(char *line);
int     	check_rooms_coordinate(char *line);
int			*check_exsisting_two_rooms_id(char *line, t_roomslst *roomslst);
t_roomslst	*search_room_in_lst(char *line, t_roomslst *roomslst);

// check_data.c
int			check_data(int n, char *line);
int			check_number_of_ants(char *line);
int     	check_rooms(char *line);
int     	check_links(char *line);

// new_in_top.c
t_top		*new_top();
int			ants_to_top(t_top *top, int ants);
void		fill_ants_to_top(int *ants_arr, int i, int *ants);
int			set_ants_moving_arr(int size, t_way **way_arr);

// new_structs
t_farm		*newfarm(void);
t_roomslst	*newroomslst();
void		set_end_of_map(int **arr, int size);
t_way		*new_way(int *room_way, int way_length_now);
int			*new_filled_start_int_arr(int start_node, int size);
t_top		*new_top();

// adding.c
int			add_each_room(t_roomslst **roomslst, char *line, int *id);
void		add_next_line_to_file(char **file, char *line);
int			**add_link_to_the_map(int **map, int *two_link_id);
int			*two_link_id(int a, int b);
int			free_line_and_replace_gnl(char **line);

// analyze.c
int			set_all_ways(t_farm *farm);
int			search_and_add_way(t_farm *farm, int *room_way_now, int way_length_now);
int			top_ways(t_farm *farm);
int			search_top(t_farm *farm,  t_way *way_now, int ants_come, int n_of_ids);

// moving.c
int step_moving(t_top *top);
void	moving_in_each_way(t_way *way, int i_way, int *ants_i, int *size);
void show_step_moving(t_top *top, t_roomslst *roomslst);
void	show_each_way_moving(t_way *way, t_roomslst *roomslst);
// searching.c
t_roomslst	*search_room_by_id(t_roomslst *roomslst, int id);
int			room_exist(char *name, t_roomslst *roomslst);
int			room_way_length(int *room_way);
t_way		*way_before_this_length(t_way *ways, int length);
t_way		*search_way_by_id(t_way *all_ways, int id);

// work_with_ways.c
void		add_way_by_increasing_length(t_way **ways, t_way **add_it);
void		set_ways_id_and_n_all_ways(t_farm *farm);
void		update_top(t_top *top,  t_way **cur_top, int cur_n_ids, int cur_steps);//witout_ants

//  intersection.c
int	no_last_way_intersec(t_way **cur_top, int cur_n_ids, t_way *way_now);
int			room_exist_in_current_top(int room_id, t_way **cur_top);
int			room_exist_in_one_current_top(int room_id, t_way *one_top);
int			change_ants_come(t_way **top, int n_of_ids);
int			count_steps(int ants_come, int ants, int cur_n_ids);

#endif
// norme
// showing help
/* ************************************************************************** */