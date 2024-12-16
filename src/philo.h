/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:02:36 by palu              #+#    #+#             */
/*   Updated: 2024/12/16 11:44:02 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <errno.h>
# define DEBUG_MODE 0

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}			t_philo_status;

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
	long		last_meal_time;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thrd_id;
	t_mtx		philo_mutex;
	t_data		*table;
}				t_philo;

typedef struct s_data
{
	long		nbr_philo;
	long		t_to_die;
	long		t_to_eat;
	long		t_to_sleep;
	long		limit_meals;
	long		start_sim;
	bool		end_sim;
	bool		all_threads_ready;
	long		threads_running_nbr;
	pthread_t	monitor;
	t_mtx		table_mutex;
	t_mtx		write_mutex;
	t_fork		*forks;
	t_philo		*philos;
}				t_data;

long		ft_atol(const char *str);
const char	*valid_input(const char *str);
bool		is_space(char c);
bool		is_digit(char c);

int			arg_init(t_data *data, char **argv);

void		mutex_handled(t_mtx	*mutex, t_opcode opcode);

void		thread_handled(pthread_t *thread, void *(*foo)(void *),
				void *data_t, t_opcode opcode);

int			data_init(t_data *data);

void		dinner_start(t_data *data);
void		*dinner_simulation(void *data_sim);
void		thinking(t_philo *philo, bool pre_sim);
void		*lone_philo(void *arg);

void		set_long(t_mtx *mutex, long *dest, long value);
long		get_long(t_mtx *mutex, long *value);
bool		get_bool(t_mtx *mutex, bool *value);
void		set_bool(t_mtx *mutex, bool *dest, bool value);
bool		simulation_finished(t_data *data);

void		wait_all_threads(t_data *data);
bool		all_threads_running(t_mtx *mutex, long *threads, long philo_nbr);
void		increase_long(t_mtx *mutex, long *value);

long		gettime(t_time_code time_code);
void		precise_usleep(long usec, t_data *data);
void		desynchronize(t_philo *philo);

void		write_status(t_philo_status status, t_philo *philo, bool debug);
void		write_status_debug(t_philo_status status, t_philo *philo,
				long elapsed);

void		*monitor_dinner(void *data);

void		clean(t_data *data);

#endif