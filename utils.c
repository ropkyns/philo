/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:59:49 by paulmart          #+#    #+#             */
/*   Updated: 2024/07/18 17:27:40 by paulmart         ###   ########.fr       */
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
	while(is_space(str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_exit("can't get negative numbere");
	if (!is_digit(*str))
		error_exit("input is an invalid digit");
	nbr = str;
	
}

long	ft_atol(const char *str)
{
	long	nb;

	nb = 0;
	
}
