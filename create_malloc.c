/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:40:18 by aadenan           #+#    #+#             */
/*   Updated: 2024/07/08 18:35:30 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_malloc(t_data *data)
{
	data->philo = malloc(sizeof(pthread_t) * data->philo_nbr);
	if (data->philo == NULL)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_nbr);
	if (data->forks == NULL)
	{
		free(data->philo);
		return (1);
	}
	data->philo_data = malloc(sizeof(t_philo) * data->philo_nbr);
	if (data->philo_data == NULL)
	{
		free(data->philo);
		free(data->forks);
		return (1);
	}
	return (0);
}
