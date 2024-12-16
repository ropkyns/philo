/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:59:49 by paulmart          #+#    #+#             */
/*   Updated: 2024/12/16 11:44:00 by paulmart         ###   ########.fr       */
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
		return (printf("Can't get negative numbere"), NULL);
	if (!is_digit(*str))
		return (printf("Input is an invalid digit"), NULL);
	nbr = str;
	while (is_digit(*str++))
		len++;
	if (len > 10)
		return (printf("Value too big"), NULL);
	return (nbr);
}

long	ft_atol(const char *str)
{
	long	nb;

	nb = 0;
	str = valid_input(str);
	if (str == NULL)
		return (-1);
	while (is_digit(*str))
		nb = (nb * 10) + (*str++ - 48);
	if (nb > INT_MAX)
		return (printf("Value too big"), -1);
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
