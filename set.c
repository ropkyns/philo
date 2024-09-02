/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:16:31 by paulmart          #+#    #+#             */
/*   Updated: 2024/09/02 15:42:28 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(t_mtx *mutex, bool *dest, bool value)
{
	mutex_handled(mutex, LOCK);
	*dest = value;
	mutex_handled(mutex, UNLOCK);
}

bool	get_bool(t_mtx *mutex, bool *value)
{
	bool	ret;

	mutex_handled(mutex, LOCK);
	ret = *value;
	mutex_handled(mutex, UNLOCK);
	return (ret);
}

long	get_long(t_mtx *mutex, long *value)
{
	long	ret;

	mutex_handled(mutex, LOCK);
	ret = *value;
	mutex_handled(mutex, UNLOCK);
}

void	set_long(t_mtx *mutex, long *dest, long *value)
{
	mutex_handled(mutex, LOCK);
	*dest = value;
	mutex_handled(mutex, UNLOCK);
}

bool	simulation_finished(t_data *data)
{
	return (get_bool(&data->table_mutex, &data->end_sim));
}
