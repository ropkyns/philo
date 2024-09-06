/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:01:16 by paulmart          #+#    #+#             */
/*   Updated: 2024/09/06 19:37:00 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	t_to_die;

	if (get_bool(&philo->philo_mutex, &philo->max_dinner))
		return (false);
	elapsed = gettime(MILLISECOND) - get_long(&philo->philo_mutex, &philo->last_meal_time);
	t_to_die = philo->table->t_to_die / 1e3;
	printf("\n%ld : %ld\n", elapsed, t_to_die);
		if (elapsed > t_to_die)
		return (true);
	return (false);
}

void	*monitor_dinner(void *data_monitor)
{
	int		i;
	t_data	*data;

	data = (t_data *)data_monitor;
	while (!all_threads_running(&data->table_mutex,
			&data->threads_running_nbr, data->nbr_philo))
		;
	while (!simulation_finished(data))
	{
		i = -1;
		while (data->nbr_philo > ++i && !simulation_finished(data))
		{
			if (philo_died(data->philos + i))
			{
				set_bool(&data->table_mutex, &data->end_sim, true);
				write_status(DIED, data->philos + i, DEBUG_MODE);
			}
		}
	}
	return (NULL);
}
