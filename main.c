/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:02:23 by palu              #+#    #+#             */
/*   Updated: 2024/07/18 16:59:36 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	arg_init(t_data *data, char *argv)
{
	data->nbr_philo = ft_atol(argv[1]);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 6 | argc == 5)
	{

	}
	else
		error_exit("wrong intput\nTry for exemple ./philo 5 800 200 200 [5]");
	return (0);
}
