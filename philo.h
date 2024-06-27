/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:48:39 by aadenan           #+#    #+#             */
/*   Updated: 2024/06/27 17:39:30 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// LIBFT IS NOT AUTHORIZED

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <pthread.h>
#include <sys/time.h>
// #include <sys/types.h> // To check again
// #include <sys/wait.h> // To check again
#include <stdio.h>

// Define color codes
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

typedef struct s_philo
{
	int	temp;
}	t_philo;

typedef struct s_data
{
	int		philo_nbr;
	int		time_to_eat;
	int		time_to_sleep;
	int		time_to_die;
	int		meals_nbr;
	int		stop_flag;
	pthread_t	*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal_time_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	stop_mutex;
	t_philo		*philo_data;
}	t_data;

int	parse_input(t_data *data, char **argv);
int	data_init(t_data *data);
int	create_malloc(t_data *node);
int	create_lock(t_data *data);
void	ft_free(t_data **data);
