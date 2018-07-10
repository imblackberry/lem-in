#include "../headers/lem_in.h"

int	add_each_room(t_roomslst **roomslst, char *line, int id)
{
	t_roomslst *new;

	new = NULL;
	new = newroomslst();
	if (new != NULL)
	{
		new->id = id;
		new->name = ft_strsub(line, 0, ft_chrposition(line, ' '));
	}
	if (*roomslst == NULL)
		*roomslst = new;
	else
		new->next = *roomslst;
	*roomslst = new;
	return (1);
}

void	add_next_line_to_file(char **file, char *line)
{
	char *newline;

	newline = ft_strdup("\n");
	if (*file == NULL)
		*file = ft_strdup(line);
	else
		ft_join_free(file, line);
	ft_join_free(file, newline);
	ft_printf("FILE = %s\n", *file);
    if (line != NULL)
        free(line);
	ft_strdel(&newline);
}

int **add_link_to_map(int **map, t_roomslst *roomslst, char *line)
{
    int id_from;
    int id_to;
    char *name;

    name = ft_strchr(line, '-') + 1;
    id_to = search_room_id(roomslst, name);
    name = ft_strsub(line, 0, ft_chrposition(line, '-'));
    id_from = search_room_id(roomslst, name);
    ft_strdel(&name);
    ft_printf("FROM %d, TO %d\n", id_from, id_to);
    if (id_from < 1 || id_to < 1)
        return NULL;
    map[id_from - 1][id_to - 1] = 1;
    return (map);
}

int search_room_id(t_roomslst *roomslst, char *name)
{
   while (roomslst != NULL)
   {
       ft_printf("NAME = [%s] NAME LST = [%s]\n", name, roomslst->name);
        if (ft_strcmp(roomslst->name, name) == 0)
            return (roomslst->id);
        else
           roomslst = roomslst->next;
   }
   return (0);
}