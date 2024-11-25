/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:36:09 by paulmart          #+#    #+#             */
/*   Updated: 2024/11/25 12:34:56 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status_debug(t_philo_status status, t_philo *philo, long elapsed)
{
	if (status == TAKE_FIRST_FORK && !simulation_finished(philo->table))
		printf("%-6ld %d has taken the first fork (id : %d)\n", elapsed,
			philo->index, philo->first_fork->fork_index);
	else if (status == TAKE_SECOND_FORK && !simulation_finished(philo->table))
		printf("%-6ld %d has taken the second fork (id : %d)\n", elapsed,
			philo->index, philo->second_fork->fork_index);
	else if (status == EATING && !simulation_finished(philo->table))
		printf("%-6ld %d is eating (meal nb : %ld)\n", elapsed,
			philo->index, philo->number_dinner);
	else if (status == SLEEPING && !simulation_finished(philo->table))
		printf("%-6ld %d is sleeping\n", elapsed, philo->index);
	else if (status == THINKING && !simulation_finished(philo->table))
		printf("%-6ld %d is thinking\n", elapsed, philo->index);
	else if (status == DIED)
		printf("%-6ld %d died\n", elapsed, philo->index);
}

void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long	elapsed;

	elapsed = gettime(MILLISECOND) - philo->table->start_sim;
	if (philo->max_dinner)
		return ;
	mutex_handled(&philo->table->write_mutex, LOCK);
	if (debug)
		write_status_debug(status, philo, elapsed);
	else
	{
		if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK)
			&& !simulation_finished(philo->table))
			printf("%-6ld %d has taken a fork\n", elapsed, philo->index);
		else if (status == EATING && !simulation_finished(philo->table))
			printf("%-6ld %d is eating\n", elapsed, philo->index);
		else if (status == SLEEPING && !simulation_finished(philo->table))
			printf("%-6ld %d is sleeping\n", elapsed, philo->index);
		else if (status == THINKING && !simulation_finished(philo->table))
			printf("%-6ld %d is thinking\n", elapsed, philo->index);
		else if (status == DIED)
			printf("%-6ld %d died\n", elapsed, philo->index);
	}
	mutex_handled(&philo->table->write_mutex, UNLOCK);
}
