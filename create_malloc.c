/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:40:18 by aadenan           #+#    #+#             */
/*   Updated: 2024/07/01 14:33:39 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_malloc(t_data *data)
{
	printf(YELLOW "---- create_malloc init ----\n" RESET);
	data->philo = malloc(sizeof(pthread_t) * data->philo_nbr);
	if (data->philo == NULL)
		return (1);
	printf("data->philo was malloc-ed\n");
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_nbr);
	if (data->forks == NULL)
	{
		free(data->philo);
		return (1);
	}
	printf("data->forks was malloc-ed\n");
	data->philo_data = malloc(sizeof(t_philo) * data->philo_nbr);
	if (data->philo_data == NULL)
	{
		free(data->philo);
		free(data->forks);
		return (1);
	}
	printf("data->philo_data was malloc-ed\n");
	return (0);
}