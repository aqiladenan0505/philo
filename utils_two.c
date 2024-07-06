/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:38:22 by aadenan           #+#    #+#             */
/*   Updated: 2024/07/06 14:50:20 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	print_state(philo, "is thinking");
	if (philo->data->philo_nbr % 2 == 0)
		return ;
	t_eat = philo->data->time_to_eat;
	t_sleep = philo->data->time_to_sleep;
	t_think = t_eat * 2 - t_sleep;
	if (t_think < 0)
		t_think = 0;
	usleep(philo->data->time_to_sleep * 0.42);
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
		if (philo->data->stop_flag == 1)
		{
			pthread_mutex_unlock(&philo->forks[philo->left_fork]);
			return ;
		}
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(&philo->forks[philo->right_fork]);
		if (philo->data->stop_flag == 1)
		{
			pthread_mutex_unlock(&philo->forks[philo->left_fork]);
			pthread_mutex_unlock(&philo->forks[philo->right_fork]);
			return ;
		}
		print_state(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->forks[philo->right_fork]);
		if (philo->data->stop_flag == 1)
		{
			pthread_mutex_unlock(&philo->forks[philo->right_fork]);
			return ;
		}
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(&philo->forks[philo->left_fork]);
		if (philo->data->stop_flag == 1)
		{
			pthread_mutex_unlock(&philo->forks[philo->left_fork]);
			pthread_mutex_unlock(&philo->forks[philo->right_fork]);
			return ;
		}
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
