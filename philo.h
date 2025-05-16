#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	long			philo_count;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meals_required;
	long			simulation_end;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	state_mutex;
	pthread_mutex_t	print_mutex;
	t_philo			*philosophers;
}	t_table;

typedef struct s_philo
{
	int			id;
	int			left_fork;
	int			right_fork;
	int			meals_eaten;
	long long	last_meal_time;
	pthread_t	thread;
	t_table		*table;
}	t_philo;

void	welcome_guests(int argc, char **argv, t_table *table);

#endif