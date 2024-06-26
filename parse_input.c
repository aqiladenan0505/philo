/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:04:38 by aadenan           #+#    #+#             */
/*   Updated: 2024/06/26 19:13:40 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Fix ft_atoi
static int	ft_atoi(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] != '\0')
	{
		nbr = (nbr * i) + (str[i] - '0');
		i++;
	}
	return (nbr);
}
// This function scans for non-number
static int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))
		{
			printf("Input contains non-number\n");
			return (1);
		}
		i++;
	}
	return (0);
}

// This function ensure input is not beyond int max
static int	ft_intmax(char *str)
{
	int	i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (str[i] != '\0')
		i++;
	if (i > 10)
	{
		printf("Number len is bigger than 10\n");
		return (1);
	}
	i = 0;
	while (str[i] != '\0')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	if (nbr > INT_MAX)
	{
		printf("Number is bigger than INT_MAX\n");
		return (1);
	}
	return (0);
}
// This function validate all the numbers in argv
static int	check_valid(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_isnum(argv[i]) == 1 || ft_intmax(argv[i]) == 1)
		{
			printf("Index %d is invalid.\n", i);
			return (1);
		}
		printf("Checking input %d\n", i);
		if (ft_isnum(argv[i]) == 1 || ft_intmax(argv[i]) == 1)
		{
			printf("Input %d is invalid.\n", i);
			return (1);
		}
		printf("Input %d is valid.\n", i);
		i++;
	}
	return (0);
}

// This function parse input
int	parse_input(t_data *data, char **argv)
{
	if (check_valid(argv) == 1)
		return (1);
	data->philo_nbr = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->meals_nbr = ft_atoi(argv[5]);
	else
		data->meals_nbr = -1;
	return (0);
}
