/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_dinner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:31:54 by aadenan           #+#    #+#             */
/*   Updated: 2024/07/10 13:10:08 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	meal_complete(t_data *data, int philo_nbr)
{
	int	i;

	i = 0;
	if (data->meals_nbr == -1)
		return (0);
	while (i < philo_nbr)
	{
		pthread_mutex_lock(data->philo_data[i].meal_time_mutex);
		if (data->philo_data[i].meals_eaten < data->meals_nbr)
		{
			pthread_mutex_unlock(data->philo_data[i].meal_time_mutex);
			return (0);
		}
		pthread_mutex_unlock(data->philo_data[i].meal_time_mutex);
		i++;
	}
	return (1);
}

static int	check_meals(t_philo *philo)
{
	if (philo->meals_nbr != -1 && philo->meals_eaten >= philo->meals_nbr)
		return (1);
	else
		return (0);
}

void	*routine_two(void *arg)
{
	int		flag;
	t_philo	*philo;

	flag = 0;
	philo = (t_philo *)arg;
	while (1)
	{
		if (flag == 0)
			print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->stop_mutex);
		if (philo->data->stop_flag == 1)
		{
			pthread_mutex_unlock(philo->stop_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->stop_mutex);
		flag = 1;
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(philo->stop_mutex);
		if (check_meals(philo) == 1 || philo->data->stop_flag == 1)
		{
			pthread_mutex_unlock(philo->stop_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->stop_mutex);
		if (eating_routine(philo) == 1)
			break ;
		if (check_meals(philo) == 1 || flag_check(philo) == 1)
			break ;
		sleep_philo(philo);
		if (flag_check(philo) == 1)
			break ;
		think(philo);
	}
	return (NULL);
}

void	execute_dinner(t_data *data)
{
	int	i;

	i = 0;
	if (data->philo_nbr > 1)
	{
		while (i < data->philo_nbr)
		{
			pthread_create(&data->philo[i], NULL, &routine,
				&data->philo_data[i]);
			i++;
		}
	}
	else
		pthread_create(&data->philo[i], NULL, &routine_two,
			&data->philo_data[i]);
	check_and_print_death(data);
	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_join(data->philo[i], NULL);
		i++;
	}
}
