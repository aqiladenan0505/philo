/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:48:39 by aadenan           #+#    #+#             */
/*   Updated: 2024/07/10 13:10:34 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				meals_eaten;
	int				meals_nbr;
	int				stop_flag;
	long			last_meal_time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*meal_time_mutex;
	pthread_mutex_t	*stop_mutex;
	t_data			*data;

}	t_philo;

typedef struct s_data
{
	int				philo_nbr;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				meals_nbr;
	int				stop_flag;
	long			initial_time;
	pthread_t		*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal_time_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	stop_mutex;
	t_philo			*philo_data;
}	t_data;

int		parse_input(t_data *data, char **argv);
int		data_init(t_data *data);
int		create_malloc(t_data *node);
int		create_lock(t_data *data);
int		take_forks(t_philo *philo);
int		flag_check(t_philo *philo);
int		eating_routine(t_philo *philo);
int		meal_complete(t_data *data, int philo_nbr);
long	get_current_time(void);
void	create_philo(t_data *data);
void	execute_dinner(t_data *data);
void	free_all(t_data *data);
void	eat(t_philo *philo);
void	put_down_forks(t_philo *philo);
void	sleep_philo(t_philo *philo);
void	think(t_philo *philo);
void	print_state(t_philo *philo, const char *state);
void	check_and_print_death(t_data *data);
#endif
