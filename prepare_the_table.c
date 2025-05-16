#include "philo.h"


void	exit_error(void)
{
	printf("Error: arguments error \n");
	exit(1);
}

static long	ft_atol(char *str)
{
	long	result;
	int		sign;
	long	prev;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		prev = result;
		result = result * 10 + (*str - '0') * sign;
		if (sign == 1 && result < prev)
			exit_error();
		str++;
	}
	if (*str)
		exit_error();
	return (result);
}

void	welcome_guests(int argc, char **argv, t_table *table)
{
	table->philo_count = ft_atol(argv[1]);
	if (table->philo_count > 200)
		exit_error();
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	table->simulation_end = -1;
	if (argc == 6)
		table->simulation_end = ft_atol(argv[5]);
}
void	bring_forks(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_count);
	i = 0;
	while (i < table->philo_count)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->state_mutex, NULL);
	pthread_mutex_init(&table->print_mutex, NULL);
}
void	prepare_the_table(t_table *table)
{
	bring_forks(table);
	start_time(table);
	open_the_door(table);
}
