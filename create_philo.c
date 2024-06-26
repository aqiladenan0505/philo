/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:46:17 by aadenan           #+#    #+#             */
/*   Updated: 2024/06/22 18:54:12 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Threads are still running after one dies
void *ft_simulation(void* arg)
{
    philosopher_t *philosopher = (philosopher_t *)arg;
    t_data *data = philosopher->data;

    while (1)
    {
        // Check if the simulation is still running
        pthread_mutex_lock(&data->running_mutex);
        if (data->simulation_running == 0)
        {
            pthread_mutex_unlock(&data->running_mutex);
            break;
        }
        pthread_mutex_unlock(&data->running_mutex);

        take_forks(philosopher);
        eat(philosopher);
        put_down_forks(philosopher);
        sleep(philosopher);
        think(philosopher);

        if (check_meals(philosopher))
            break;
        if (check_death(philosopher))
        {
            print_state(philosopher, "died");
            pthread_mutex_lock(&data->running_mutex);
            data->simulation_running = 0;
            pthread_mutex_unlock(&data->running_mutex);
            return (NULL);
        }
    }
    return (NULL);
}

void create_philo(t_data *data)
{
    int i = 0;

    data->simulation_running = 1;  // Set the simulation as running
    while (i < data->philo_nbr)
    {
        data->philo_data[i].id = i + 1;
        data->philo_data[i].left_fork = i;
        data->philo_data[i].right_fork = (i + 1) % data->philo_nbr;
        data->philo_data[i].meals_eaten = 0;
        data->philo_data[i].last_meal_time = get_current_time();
        data->philo_data[i].time_to_die = data->time_to_die;
        data->philo_data[i].time_to_eat = data->time_to_eat;
        data->philo_data[i].time_to_sleep = data->time_to_sleep;
        data->philo_data[i].meals_nbr = data->meals_nbr;
        data->philo_data[i].forks = data->forks;
        data->philo_data[i].print_mutex = &data->print_mutex;
        data->philo_data[i].meal_time_mutex = &data->meal_time_mutex;
        data->philosopher_data[i].stop_flag = &sim->stop_flag;
        data->philosopher_data[i].stop_mutex = &sim->stop_mutex;
        pthread_create(&data->philo[i], NULL, ft_simulation, &data->philo_data[i]);
        i++;
    }
}
