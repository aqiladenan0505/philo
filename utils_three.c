/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:17:20 by aadenan           #+#    #+#             */
/*   Updated: 2024/07/09 16:22:37 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_two(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->right_fork]);
	pthread_mutex_lock(philo->stop_mutex);
	if (philo->data->stop_flag == 1)
	{
		pthread_mutex_unlock(philo->stop_mutex);
		pthread_mutex_unlock(&philo->forks[philo->right_fork]);
		return (1);
	}
	pthread_mutex_unlock(philo->stop_mutex);
	print_state(philo, "has taken a fork");
	pthread_mutex_lock(&philo->forks[philo->left_fork]);
	pthread_mutex_lock(philo->stop_mutex);
	if (philo->data->stop_flag == 1)
	{
		pthread_mutex_unlock(philo->stop_mutex);
		pthread_mutex_unlock(&philo->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->forks[philo->right_fork]);
		return (1);
	}
	pthread_mutex_unlock(philo->stop_mutex);
	print_state(philo, "has taken a fork");
	return (0);
}

static int	ft_one(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->left_fork]);
	pthread_mutex_lock(philo->stop_mutex);
	if (philo->data->stop_flag == 1)
	{
		pthread_mutex_unlock(philo->stop_mutex);
		pthread_mutex_unlock(&philo->forks[philo->left_fork]);
		return (1);
	}
	pthread_mutex_unlock(philo->stop_mutex);
	print_state(philo, "has taken a fork");
	pthread_mutex_lock(&philo->forks[philo->right_fork]);
	pthread_mutex_lock(philo->stop_mutex);
	if (philo->data->stop_flag == 1)
	{
		pthread_mutex_unlock(philo->stop_mutex);
		pthread_mutex_unlock(&philo->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->forks[philo->right_fork]);
		return (1);
	}
	pthread_mutex_unlock(philo->stop_mutex);
	print_state(philo, "has taken a fork");
	return (0);
}

int	take_forks(t_philo *philo)
{
	if (philo->left_fork < philo->right_fork)
	{
		if (ft_one(philo) == 1)
			return (1);
	}
	else
	{
		if (ft_two(philo) == 1)
			return (1);
	}
	return (0);
}
