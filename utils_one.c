/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:19:34 by aadenan           #+#    #+#             */
/*   Updated: 2024/07/01 15:20:39 by aadenan          ###   ########.fr       */
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

long	get_current_time(void)
{
	struct	timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
