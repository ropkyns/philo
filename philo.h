/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:02:36 by palu              #+#    #+#             */
/*   Updated: 2024/07/21 16:33:02 by palu             ###   ########.fr       */
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
#include <errno.h>

typedef enum	e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}			t_opcode;

typedef pthread_mutex_t	t_mtx;

typedef struct s_data	t_data;

typedef struct s_fork
{
	t_mtx	fork;
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
	t_data		*table;
}				t_philo;

typedef struct s_data
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
}				t_data;

void	error_exit(const char *str_error);
long	ft_atol(const char *str);
void	arg_init(t_data *data, char **argv);
void	*malloc_checked(size_t bytes);

#endif