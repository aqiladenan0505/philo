/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:48:39 by aadenan           #+#    #+#             */
/*   Updated: 2024/06/26 18:46:23 by aadenan          ###   ########.fr       */
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

typedef struct s_philo
{
	int	temp;
}	t_philo;

typedef struct s_data
{
	int	philo_nbr;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_die;
	int	meals_nbr;
	int	stop_flag;
	pthread_t *philo;
	pthread_mutex_t *forks;
	t_philo *philo_data;
}	t_data;

int	parse_input(t_data *data, char **argv);
int	create_malloc(t_data *node);
