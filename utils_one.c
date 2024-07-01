/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:19:34 by aadenan           #+#    #+#             */
/*   Updated: 2024/07/01 15:04:21 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_data **data)
{
    t_data	*temp;

    temp = *data;
    free(temp->philo);
    free(temp->forks);
    free(temp->philo_data);
    temp->philo = NULL;
    temp->forks = NULL;
    temp->philo_data = NULL;
}

long	get_current_time(void)
{
	struct	timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
