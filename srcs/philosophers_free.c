/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:57:57 by gmayweat          #+#    #+#             */
/*   Updated: 2021/07/23 22:18:54 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	free_philos(t_phil *philos)
{
	int	i;

	i = 0;
	while ((philos + i)->table)
	{
		if (philos[i].left)
			pthread_mutex_destroy(philos[i].left);
		free(philos[i].left);
		++i;
	}
	free(philos);
}

void	philosophers_free(t_table *table)
{
	if (table->philos)
		free_philos(table->philos);
	if (table->orator)
	{
		pthread_mutex_destroy(table->orator);
		free(table->orator);
	}
	if (table->pthreads)
		free(table->pthreads);
}
