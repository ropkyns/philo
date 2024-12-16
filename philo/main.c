/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:02:23 by palu              #+#    #+#             */
/*   Updated: 2024/12/16 11:44:04 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_init(t_data *data, char **argv)
{
	data->nbr_philo = ft_atol(argv[1]);
	data->t_to_die = ft_atol(argv[2]) * 1e3;
	data->t_to_eat = ft_atol(argv[3]) * 1e3;
	data->t_to_sleep = ft_atol(argv[4]) * 1e3;
	if (data->t_to_die < 6e4
		|| data->t_to_eat < 6e4 || data->t_to_sleep < 6e4
		|| data->nbr_philo == -1)
		return (printf("Timer need to be bigger than 60ms"), -1);
	if (argv[5])
	{
		data->limit_meals = ft_atol(argv[5]);
		if (data->limit_meals == -1)
			return (-1);
	}
	else
		data->limit_meals = -1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if ((argc == 6) | (argc == 5))
	{
		if (arg_init(&data, argv) == -1)
			return (1);
		if (data_init(&data) == -1)
			return (clean(&data), 1);
		dinner_start(&data);
		clean(&data);
	}
	else
		return (printf("wrong intput\nTry for exemple ./philo 5 800 200 200 [5]")
			, 1);
	return (0);
}
