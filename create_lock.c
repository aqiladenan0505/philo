/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:42:41 by aadenan           #+#    #+#             */
/*   Updated: 2024/06/22 18:43:32 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	create_lock(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->meal_time_mutex, NULL);
	pthread_mutex_init(&data->stop_mutex, NULL);
	while (i < data->philo_nbr)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}
