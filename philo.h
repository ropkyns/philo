/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:02:36 by palu              #+#    #+#             */
/*   Updated: 2024/07/16 11:23:21 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_data	t_data;

typedef struct s_fork
{
	t_mutex	fork;
	int		fork_index;
}				t_fork;

typedef struct s_philo
{
	int			index;
	long		number_dinner;
	bool		max_dinner;
	long		last_diner_time;
	t_fork		*lfork;
	t_fork		*rfork;
	pthread_t	thrd_id;
}					t_philo;

struct s_data
{
	long	nbr_philo;
	long	t_to_die;
	long	t_to_eat;
	long	t_to_sleep;
	long	limit_meal;
	long	start_sim;
	bool	end_sim;
	t_fork	*forks;
	t_philo	*philos;

};


#endif