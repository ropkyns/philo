/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:11:15 by palu              #+#    #+#             */
/*   Updated: 2024/09/12 12:28:11 by paulmart         ###   ########.fr       */
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
		mutex_handled(&philo->philo_mutex, INIT);
		assign_fork(philo, data->forks, i);
	}
}

int	data_init(t_data *data)
{
	int		i;

	i = -1;
	data->end_sim = false;
	data->all_threads_ready = false;
	data->threads_running_nbr = 0;
	data->philos = malloc(sizeof(t_philo) * data->nbr_philo);
	if (data->philos == NULL)
		return (-1);
	mutex_handled(&data->table_mutex, INIT);
	mutex_handled(&data->write_mutex, INIT);
	data->forks = malloc(sizeof(t_fork) * data->nbr_philo);
	if (!data->forks)
		return (-1);
	while (data->nbr_philo > ++i)
	{
		mutex_handled(&data->forks[i].fork, INIT);
		data->forks[i].fork_index = i;
	}
	philo_init(data);
	return (0);
}
