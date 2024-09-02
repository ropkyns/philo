/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:02:23 by palu              #+#    #+#             */
/*   Updated: 2024/09/02 14:05:55 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	arg_init(t_data *data, char **argv)
{
	data->nbr_philo = ft_atol(argv[1]);
	data->t_to_die = ft_atol(argv[2]) * 1e3;
	data->t_to_eat = ft_atol(argv[3]) * 1e3;
	data->t_to_sleep = ft_atol(argv[4]) * 1e3;
	if (data->t_to_die < 6e4
		|| data->t_to_eat < 6e4
		|| data->t_to_sleep < 6e4)
		error_exit("Timer need to be bigger than 60ms");
	if (argv[5])
		data->limit_meal = ft_atol(argv[5]);
	else
		data->limit_meal = -1;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 6 | argc == 5)
	{
		arg_init(&data, argv);
		data_init(&data);
		dinner_start(&data);//todo
		clean(&data);//todo
	}
	else
		error_exit("wrong intput\nTry for exemple ./philo 5 800 200 200 [5]");
	return (0);
}
