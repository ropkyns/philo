/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:02:36 by palu              #+#    #+#             */
/*   Updated: 2024/09/02 16:25:47 by paulmart         ###   ########.fr       */
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
# include <errno.h>

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}			t_opcode;

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}			t_time_code;

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
	t_fork		*first_fork;
	t_fork		*second_fork;
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
	bool	all_threads_ready;
	t_mtx	table_mutex;
	t_fork	*forks;
	t_philo	*philos;
}				t_data;

void		error_exit(const char *str_error);
long		ft_atol(const char *str);
void		arg_init(t_data *data, char **argv);
void		*malloc_checked(size_t bytes);

void		mutex_handled(t_mtx	*mutex, t_opcode opcode);
static void	handle_mutex_error(int status, t_opcode opcode);

static void	handle_threads_error(int status, t_opcode opcode);
void		thread_handled(pthread_t *thread, void *(*foo)(void *),
				void *data_t, t_opcode opcode);
				
void		data_init(t_data *data);

void		set_long(t_mtx *mutex, long *dest, long *value);
long		get_long(t_mtx *mutex, long *value);
bool		get_bool(t_mtx *mutex, bool *value);
void		set_bool(t_mtx *mutex, bool *dest, bool value);
bool		simulation_finished(t_data *data);

void	wait_all_threads(t_data *data);


#endif