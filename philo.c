/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:12:14 by aadenan           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/06/20 14:43:30 by aadenan          ###   ########.fr       */
=======
/*   Updated: 2024/06/18 14:54:24 by aadenan          ###   ########.fr       */
>>>>>>> 316c3a0 (Added header file)
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
<<<<<<< HEAD
	t_data	data;
	if (argc == 5 || argc == 6)
	{
		if (parse_input(&data, argv) == 1)
			return (0);
		printf("All input is valid\n");
		printf("philo_nbr: %d\n", data.philo_nbr);
		printf("time_to_die: %d\n", data.time_to_die);
		printf("time_to_eat: %d\n", data.time_to_eat);
		printf("time_to_sleep: %d\n", data.time_to_sleep);
		printf("meals_nbr: %d\n", data.meals_nbr);
=======
	if (argc == 5 || argc == 6)
	{
		parse_input(argv);
>>>>>>> 316c3a0 (Added header file)
		// data_init();
		// execute_philo();
		// free_all();
	}
	else
	{
<<<<<<< HEAD
		printf("Wrong number of arguments\n");
=======
>>>>>>> 316c3a0 (Added header file)
		// output_error();
	}
	return (0);
}
