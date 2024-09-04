/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:01:16 by paulmart          #+#    #+#             */
/*   Updated: 2024/09/04 17:12:33 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_dinner(void *data)
{
	t_data	*data_monitor;

	data_monitor = (t_data *)data;

	while (!all_thread_running(&data_monitor->table_mutex, 
			&data_monitor->threads_running_nbr))
		;
	
}