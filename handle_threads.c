/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:25:18 by paulmart          #+#    #+#             */
/*   Updated: 2024/09/04 11:40:47 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	handle_threads_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		error_exit("No resources to create another thread");
	else if (status == EPERM)
		error_exit("The caller does not have appropriate permission\n");
	else if (status == EINVAL && opcode == CREATE)
		error_exit("The value specified by attr is invalid.");
	else if (status == EINVAL && (opcode == JOIN || opcode == DETACH))
		error_exit("The value specified by thread is not joinable\n");
	else if (status == ESRCH)
		error_exit("No thread could be found corresponding to that"
			"specified by the given thread ID, thread.");
	else if (status == EDEADLK)
		error_exit("A deadlock was detecte or the value of"
			"thread specifies the calling thread.");
}

void	thread_handled(pthread_t *thread, void *(*foo)(void *),
	void *data_t, t_opcode opcode)
{
	if (opcode == CREATE)
		handle_threads_error(pthread_create(thread, NULL, foo, data_t), opcode);
	else if (opcode == JOIN)
		handle_threads_error(pthread_join(*thread, NULL), opcode);
	else if (opcode == DETACH)
		handle_threads_error(pthread_detach(*thread), opcode);
	else
		error_exit("Wrong opcode for thread_handle:"
			" use <CREATE> <JOIN> <DETACH>");
}
