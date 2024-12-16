/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:24:14 by paulmart          #+#    #+#             */
/*   Updated: 2024/12/16 11:44:02 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_handled(t_mtx	*mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		pthread_mutex_lock(mutex);
	else if (opcode == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (opcode == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (opcode == DESTROY)
		pthread_mutex_destroy(mutex);
}

void	thread_handled(pthread_t *thread, void *(*foo)(void *),
	void *data_t, t_opcode opcode)
{
	if (opcode == CREATE)
		pthread_create(thread, NULL, foo, data_t);
	else if (opcode == JOIN)
		pthread_join(*thread, NULL);
	else if (opcode == DETACH)
		pthread_detach(*thread);
}
