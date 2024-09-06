/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:14:34 by paulmart          #+#    #+#             */
/*   Updated: 2024/09/06 19:29:41 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*lone_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECOND));
	increase_long(&philo->table->table_mutex,
		&philo->table->threads_running_nbr);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	while (!simulation_finished(philo->table))
		usleep(200);
	return (NULL);
}

static void	thinking(t_philo *philo)
{
	write_status(THINKING, philo, DEBUG_MODE);
}

static void	eat(t_philo *philo)
{
	mutex_handled(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	mutex_handled(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECOND));
	philo->number_dinner++;
	write_status(EATING, philo, DEBUG_MODE);
	precise_usleep(philo->table->t_to_eat, philo->table);
	if (philo->table->limit_meals > 0
		&& philo->number_dinner == philo->table->limit_meals)
		set_bool(&philo->philo_mutex, &philo->max_dinner, true);
	mutex_handled(&philo->first_fork->fork, UNLOCK);
	mutex_handled(&philo->second_fork->fork, UNLOCK);
}

void	*dinner_simulation(void *data_sim)
{
	t_philo		*philo;

	philo = (t_philo *)data_sim;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECOND));
	increase_long(&philo->table->table_mutex,
		&philo->table->threads_running_nbr);
	while (!simulation_finished(philo->table))
	{
		if (philo->max_dinner)
			break ;
		eat (philo);
		write_status(SLEEPING, philo, DEBUG_MODE);
		precise_usleep(philo->table->t_to_sleep, philo->table);

		thinking(philo);
	}
	return (NULL);
}

void	dinner_start(t_data *data)
{
	int		i;

	i = -1;
	if (data->limit_meals == 0)
		return ;
	else if (data->nbr_philo == 1)
		thread_handled(&data->philos[0].thrd_id, lone_philo,
			&data->philos[0], CREATE);
	else
	{
		while (data->nbr_philo > ++i)
			thread_handled(&data->philos[i].thrd_id, dinner_simulation,
				&data->philos[i], CREATE);
	}
	thread_handled(&data->monitor, monitor_dinner, data, CREATE);
	data->start_sim = gettime(MILLISECOND);
	printf("\n%ld\n", data->start_sim);
	set_bool(&data->table_mutex, &data->all_threads_ready, true);
	i = -1;
	while (data->nbr_philo > ++i)
		thread_handled(&data->philos[i].thrd_id, NULL, NULL, JOIN);
}
