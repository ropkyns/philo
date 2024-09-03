/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:11:15 by palu              #+#    #+#             */
/*   Updated: 2024/09/03 14:56:01 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_fork(t_philo *philo, t_fork *forks, int philo_pos)
{
	int		philo_nbr;

	philo_nbr = philo->table->nbr_philo;
	philo->first_fork = &forks[(philo_pos + 1) % philo_nbr];
	philo->second_fork = &forks[philo_pos];
	if (philo->index % 2 == 0)
	{
	philo->first_fork = &forks[philo_pos];
	philo->second_fork = &forks[(philo_pos + 1) % philo_nbr];
	}
}

static void	philo_init(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (data->nbr_philo > ++i)
	{
		philo = data->philos + i;
		philo->index = i + 1;
		philo->max_dinner = false;
		philo->number_dinner = 0;
		philo->table = data;
		assign_forks(philo, data->forks, i);
	}
}

void	data_init(t_data *data)
{
	int		i;

	i = -1;
	data->end_sim = false;
	data->philos = malloc_checked(sizeof(t_philo) * data->nbr_philo);
	mutex_handled(&data->table_mutex, INIT);
	mutex_handled(&data->write_mutex, INIT);
	data->forks = malloc_checked(sizeof(t_fork) * data->nbr_philo);
	while (data->nbr_philo > ++i)
	{
		mutex_handled(&data->forks[i].fork, INIT);
		data->forks[i].fork_index = i;
	}
	philo_init(data);
}
