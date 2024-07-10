/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:19:34 by aadenan           #+#    #+#             */
/*   Updated: 2024/07/09 17:06:29 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *data)
{
	free(data->philo);
	free(data->forks);
	free(data->philo_data);
	data->philo = NULL;
	data->forks = NULL;
	data->philo_data = NULL;
}

void	print_state(t_philo *philo, const char *state)
{
	long	current_time;

	current_time = get_current_time() - philo->data->initial_time;
	pthread_mutex_lock(philo->print_mutex);
	printf("%ld %d %s\n", current_time, philo->id, state);
	pthread_mutex_unlock(philo->print_mutex);
}

long	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	flag_check(t_philo *philo)
{
	int	nbr;

	nbr = 0;
	pthread_mutex_lock(philo->stop_mutex);
	if (philo->data->stop_flag == 1)
	{
		pthread_mutex_unlock(philo->stop_mutex);
		nbr = 1;
	}
	else
		pthread_mutex_unlock(philo->stop_mutex);
	return (nbr);
}

int	eating_routine(t_philo *philo)
{
	if (take_forks(philo) == 1)
		return (1);
	usleep(42);
	if (flag_check(philo) == 1)
	{
		put_down_forks(philo);
		return (1);
	}
	eat(philo);
	put_down_forks(philo);
	return (0);
}
