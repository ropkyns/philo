/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:59:49 by paulmart          #+#    #+#             */
/*   Updated: 2024/09/06 17:44:38 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

const char	*valid_input(const char *str)
{
	int			len;
	const char	*nbr;

	len = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_exit("Can't get negative numbere");
	if (!is_digit(*str))
		error_exit("Input is an invalid digit");
	nbr = str;
	while (is_digit(*str++))
		len++;
	if (len > 10)
		error_exit("Value too big");
	return (nbr);
}

long	ft_atol(const char *str)
{
	long	nb;

	nb = 0;
	str = valid_input(str);
	while (is_digit(*str))
		nb = (nb * 10) + (*str++ - 48);
	if (nb > INT_MAX)
		error_exit("Value too big");
	return (nb);
}

void	clean(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (data->nbr_philo > ++i)
	{
		philo = data->philos + i;
		mutex_handled(&philo->philo_mutex, DESTROY);
	}
	mutex_handled(&data->write_mutex, DESTROY);
	mutex_handled(&data->table_mutex, DESTROY);
	free(data->forks);
	free(data->philos);
}