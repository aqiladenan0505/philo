/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:12:14 by aadenan           #+#    #+#             */
/*   Updated: 2024/06/26 18:41:27 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (parse_input(argv) == 1)
			return (0);
		printf("Input is correct\n");
		printf("philo_nbr: %d\n", data.philo_nbr);
		printf("time_to_die: %d\n", data.time_to_die);
		printf("time_to_eat: %d\n", data.time_to_eat);
		printf("time_to_sleep: %d\n", data.time_to_sleep);
		printf("meals_nbr: %d\n", data.meals_nbr);
		// data_init();
		// execute_philo();
		// free_all();
	}
	else
	{
		printf("Wrong number of arguments\n");
		// output_error();
	}
	return (0);
}
