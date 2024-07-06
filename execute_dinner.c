/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_dinner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:31:54 by aadenan           #+#    #+#             */
/*   Updated: 2024/07/06 15:46:45 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_and_print_death(t_data *data)
{
	int		i;
	long	last_meal;

	while (data->stop_flag == 0)
	{
		i = 0;
		while (i < data->philo_nbr)
		{
			last_meal = get_current_time() - data->philo_data[i].last_meal_time;
			if (last_meal > data->time_to_die)
			{
				pthread_mutex_lock(&data->stop_mutex);
				data->stop_flag = 1;
				pthread_mutex_unlock(&data->stop_mutex);
				print_state(&data->philo_data[i], "died");
				return (1);
			}
			i++;
		}
	}
	return (0);
}

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
	if (philo->id % 2 == 0)
		usleep(42);
	while (philo->data->stop_flag == 0)
	{
		if (check_meals(philo) == 1 || philo->data->stop_flag == 1)
			break;
		take_forks(philo);
		eat(philo);
		put_down_forks(philo);
		if (check_meals(philo) == 1 || philo->data->stop_flag == 1)
			break;
		sleep_philo(philo);
		if (philo->data->stop_flag == 1)
			break;
		think(philo);
	}
//	philo->data->stop_flag = 1;
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
	//printf("Flag 1\n");
	//printf("stop_flag: %d\n", data->stop_flag);
	if (data->stop_flag == 0)
	{
		//printf("Flag 2\n");
		check_and_print_death(data);
		//printf("Flag 3\n");
	}
	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_join(data->philo[i], NULL);
		i++;
	}
	//printf("stop_flag: %d\n", data->stop_flag);
	printf(GREEN "-------- execute_dinner done --------\n" RESET);
}
