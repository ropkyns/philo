/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:02:23 by palu              #+#    #+#             */
/*   Updated: 2024/09/06 17:45:55 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	arg_init(t_data *data, char **argv)
{
	data->nbr_philo = ft_atol(argv[1]);
	printf("%ld\n", data->nbr_philo);
	data->t_to_die = ft_atol(argv[2]) * 1e3;
	printf("%ld\n", data->t_to_die);
	data->t_to_eat = ft_atol(argv[3]) * 1e3;
	printf("%ld\n", data->t_to_eat);
	data->t_to_sleep = ft_atol(argv[4]) * 1e3;
	printf("%ld\n", data->t_to_sleep);
	if (data->t_to_die < 6e4
		|| data->t_to_eat < 6e4
		|| data->t_to_sleep < 6e4)
		error_exit("Timer need to be bigger than 60ms");
	if (argv[5])
		data->limit_meals = ft_atol(argv[5]);
	else
		data->limit_meals = -1;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 6 | argc == 5)
	{
		arg_init(&data, argv);
		data_init(&data);
		dinner_start(&data);
		clean(&data);
	}
	else
		error_exit("wrong intput\nTry for exemple ./philo 5 800 200 200 [5]");
	return (0);
}
