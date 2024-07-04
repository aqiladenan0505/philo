/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:38:22 by aadenan           #+#    #+#             */
/*   Updated: 2024/07/04 16:12:01 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	print_state(philo, "is thinking");
}

void	sleep_philo(t_philo *philo)
{
	print_state(philo, "is sleeping");
	usleep(philo->time_to_sleep * 1000);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_time_mutex);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(philo->meal_time_mutex);
	print_state(philo, CYAN "is eating" RESET);
	usleep(philo->time_to_eat * 1000);
	philo->meals_eaten++;
}

void	take_forks(t_philo *philo)
{
	if (philo->left_fork < philo->right_fork)
	{
		pthread_mutex_lock(&philo->forks[philo->left_fork]);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(&philo->forks[philo->right_fork]);
		print_state(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->forks[philo->right_fork]);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(&philo->forks[philo->left_fork]);
		print_state(philo, "has taken a fork");
	}
}

void	put_down_forks(t_philo *philo)
{
	if (philo->left_fork < philo->right_fork)
	{
		pthread_mutex_unlock(&philo->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->forks[philo->left_fork]);
	}
	else
	{
		pthread_mutex_unlock(&philo->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->forks[philo->right_fork]);
	}
}
