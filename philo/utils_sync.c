/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sync.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:49:07 by paulmart          #+#    #+#             */
/*   Updated: 2024/12/16 11:44:01 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_all_threads(t_data *data)
{
	while (!get_bool(&data->table_mutex, &data->all_threads_ready))
		usleep(1);
}

bool	all_threads_running(t_mtx *mutex, long *threads, long philo_nbr)
{
	bool	ret;

	ret = false;
	mutex_handled(mutex, LOCK);
	if (*threads == philo_nbr)
		ret = true;
	mutex_handled(mutex, UNLOCK);
	return (ret);
}

void	increase_long(t_mtx *mutex, long *value)
{
	mutex_handled(mutex, LOCK);
	(*value)++;
	mutex_handled(mutex, UNLOCK);
}

void	desynchronize(t_philo *philo)
{
	if (philo->table->nbr_philo % 2 == 0)
	{
		if (philo->index % 2 == 0)
			precise_usleep(3e4, philo->table);
	}
	else
	{
		if (philo->index % 2)
			thinking(philo, true);
	}
}
