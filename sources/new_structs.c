#include "../headers/lem_in.h"

t_farm	*newfarm(int ants)
{
	t_farm	*farm;

	farm = (t_farm*)malloc(sizeof(t_farm));
	if (farm != NULL)
	{
		farm->ants = ants;
		farm->file = NULL;
		farm->roomslst = NULL;
		farm->id_start = 0;
		farm->id_end = 0;
		farm->map = 0;
	}
	return(farm);
}

t_roomslst *newroomslst()
{
	t_roomslst *roomslst;

	roomslst = NULL;
	roomslst = (t_roomslst*)malloc(sizeof(t_roomslst));
	if (roomslst != NULL)
	{
		roomslst->id = 0;
		roomslst->name = NULL;
		roomslst->next = NULL;
	}
	return (roomslst);
}
