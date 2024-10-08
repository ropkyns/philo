/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:37:08 by paulmart          #+#    #+#             */
/*   Updated: 2024/09/02 11:24:59 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_exit(const char *str_error)
{
	printf("%s\n", str_error);
	exit(EXIT_FAILURE);
}

void	*malloc_checked(size_t bytes)
{
	void	*value;

	value = malloc(bytes);
	if (value == NULL)
		error_exit("Malloc error");
	return (value);
}
