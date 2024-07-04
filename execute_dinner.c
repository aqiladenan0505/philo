/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_dinner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:31:54 by aadenan           #+#    #+#             */
/*   Updated: 2024/07/04 15:27:37 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_meals(t_philo *philo)
{
	if (philo->meals_nbr != -1 && philo->meals_eaten >= philo->meals_nbr)
		return (1);
	else
		return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		take_forks(philo);
		eat(philo);
		put_down_forks(philo);
		sleep_philo(philo);
		think(philo);
		if (check_meals(philo) == 1)
			break;
	}
	return (NULL);
}

void	execute_dinner(t_data *data)
{
	printf(YELLOW "-------- executing dinner... --------\n" RESET);
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_create(&data->philo[i], NULL, &routine, &data->philo_data[i]);
		i++;
	}
	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_join(data->philo[i], NULL);
		i++;
	}
	printf(GREEN "-------- execute_dinner done --------\n" RESET);
}
