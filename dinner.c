/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:14:34 by paulmart          #+#    #+#             */
/*   Updated: 2024/09/03 14:12:55 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner_simulation(void *data_sim)
{
	t_philo		*philo;

	philo = (t_philo *)data_sim;
	wait_all_threads(philo->table);
	while (!simulation_finished(philo->table))
	{
		if (philo->max_dinner)
			break ;
		eat (philo);
		
		sleep;
		
		thinking(philo);
	}
	return (NULL);
}

void	dinner_start(t_data *data)
{
	int		i;

	i = -1;
	if (data->limit_meal == 0)
		return ;
	else if (data->nbr_philo == 1)
		;
	else
	{
		while (data->nbr_philo > ++i)
			thread_handled(&data->philos[i].thrd_id, dinner_simulation,
				&data->philos[i], CREATE);
	}
	data->start_sim = gettime(MILLISECOND);
	set_bool(&data->table_mutex, &data->all_threads_ready, true);
	i = -1;
	while (data->nbr_philo > ++i)
		thread_handled(data->philos[i].thrd_id, NULL, NULL, JOIN);
	
}
