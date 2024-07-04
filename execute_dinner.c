/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_dinner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:31:54 by aadenan           #+#    #+#             */
/*   Updated: 2024/07/04 10:36:32 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("Hello, world!\n");
/*
	while (check_death(philo) == 0)
	{
		// take_forks(philo);
		// eat(philo);
		// put_down_forks(philo);
		// sleep(philo);
		// think(philo);
		// if (chekc_meals(philo) == 1)
		// 	break;
	}
*/
}
void	execute_dinner(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		pthread-create(&data->philo[i], NULL, routine, &data->philo_data[i]);
		i++;
	}
	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_join(data->philo[i], NULL);
		i++;
	}
}
