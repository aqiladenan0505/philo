/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:46:17 by aadenan           #+#    #+#             */
/*   Updated: 2024/07/09 17:02:17 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		data->philo_data[i].id = i + 1;
		data->philo_data[i].left_fork = i;
		data->philo_data[i].right_fork = (i + 1) % data->philo_nbr;
		data->philo_data[i].meals_eaten = 0;
		data->philo_data[i].last_meal_time = get_current_time();
		data->philo_data[i].time_to_die = data->time_to_die;
		data->philo_data[i].time_to_eat = data->time_to_eat;
		data->philo_data[i].time_to_sleep = data->time_to_sleep;
		data->philo_data[i].meals_nbr = data->meals_nbr;
		data->philo_data[i].forks = data->forks;
		data->philo_data[i].print_mutex = &data->print_mutex;
		data->philo_data[i].meal_time_mutex = &data->meal_time_mutex;
		data->philo_data[i].stop_flag = data->stop_flag;
		data->philo_data[i].stop_mutex = &data->stop_mutex;
		data->philo_data[i].data = data;
		i++;
	}
}
