/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:42:41 by aadenan           #+#    #+#             */
/*   Updated: 2024/06/27 17:31:18 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_print_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		printf("print_mutex init failed\n");
		ft_free(&data);
		return (1);
	}
	printf("print_mutex init\n");
	return (0);
}

static int	init_meal_time_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->meal_time_mutex, NULL) != 0)
	{
		printf("meal_time_mutex init failed\n");
		ft_free(&data);
		pthread_mutex_destroy(&data->print_mutex);
		return (1);
	}
	printf("meal_time_mutex init\n");
	return (0);
}

static int	init_stop_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->stop_mutex, NULL) != 0)
	{
		printf("stop_mutex init failed\n");
		ft_free(&data);
		pthread_mutex_destroy(&data->print_mutex);
		pthread_mutex_destroy(&data->meal_time_mutex);
		return (1);
	}
	printf("stop_mutex init\n");
	return (0);
}

static int	init_forks_mutex(t_data *data)
{
	int	i;
	int	idx;

	i = 0;
	idx = 0;
	while (i < data->philo_nbr)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			printf("forks mutex init failed\n");
			ft_free(&data);
			pthread_mutex_destroy(&data->print_mutex);
			pthread_mutex_destroy(&data->meal_time_mutex);
			pthread_mutex_destroy(&data->stop_mutex);
			while (idx < i)
			{
				pthread_mutex_destroy(&data->forks[idx]);
				idx++;
			}
			return (1);
		}
		i++;
	}
	printf("All forks init\n");
	return (0);
}

int	create_lock(t_data *data)
{
	if (init_print_mutex(data) != 0)
		return (1);
	if (init_meal_time_mutex(data) != 0)
		return (1);
	if (init_stop_mutex(data) != 0)
		return (1);
	if (init_forks_mutex(data) != 0)
		return (1);
	return (0);
}
