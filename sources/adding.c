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
    free(line);
	ft_strdel(&newline);
}

int **add_link_to_the_map(int **map, int *two_link_id)
{
    int i;
    int j;

    i = two_link_id[0] - 1;
    j = two_link_id[1] - 1;
    map[i][j] = 1;
    map[j][i] = 1;
    return (map);
}

int *two_link_id(int a, int b)
{
    int *two_link_id;

    two_link_id = (int*)malloc(sizeof(int) * 2);
    two_link_id[0] = a;
    two_link_id[1] = b;
    return (two_link_id);
}

// int search_room_id(t_roomslst *roomslst, char *name)
// {
//    while (roomslst != NULL)
//    {
//        ft_printf("NAME = [%s] NAME LST = [%s]\n", name, roomslst->name);
//         if (ft_strcmp(roomslst->name, name) == 0)
//             return (roomslst->id);
//         else
//            roomslst = roomslst->next;
//    }
//    return (0);
// }