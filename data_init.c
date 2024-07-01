/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:56:46 by aadenan           #+#    #+#             */
/*   Updated: 2024/06/27 18:53:16 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	data_init(t_data *data)
{
	if (create_malloc(data) == 1)
	{
		printf("Malloc error\n");
		return (1);
	}
	if (create_lock(data) == 1)
	{
		printf("Mutex error\n");
		return (1);
	}
	create_philo(data);
	data->stop_flag = 1;
	return (0);
}
