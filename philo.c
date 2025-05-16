#include "philo.h"

int main(int argc, char **argv)
{
	t_table table;
	memset(&table, 0 , sizeof(t_table));
	if (argc < 5 || argc > 6)
	{
		printf("Error: Args number must be 4 or 5\n");
		return (1);
	}
	welcome_guests(argc, argv, &table);
	prepare_the_table(&table);
	vigil(&table);
	clean_the_table(&table);
	return (0);
}
