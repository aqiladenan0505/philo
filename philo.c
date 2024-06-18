/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:12:14 by aadenan           #+#    #+#             */
/*   Updated: 2024/06/18 14:57:38 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		parse_input(argv);
		printf("Input is correct\n");
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
