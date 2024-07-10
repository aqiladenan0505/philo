/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:12:14 by aadenan           #+#    #+#             */
/*   Updated: 2024/07/08 17:21:24 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (parse_input(&data, argv) == 1)
			return (0);
		if (data_init(&data) == 1)
			return (1);
		execute_dinner(&data);
		free_all(&data);
	}
	else
	{
		printf("Wrong number of arguments\n");
	}
	return (0);
}
