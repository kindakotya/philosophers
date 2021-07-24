/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_stdout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 21:15:42 by gmayweat          #+#    #+#             */
/*   Updated: 2021/07/24 21:30:43 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	orator_says(char *str, t_phil *phil, t_table *table)
{
	if (doctor(table))
		return ;
	pthread_mutex_lock(table->orator);
	if (!table->is_dead)
	{
		if (phil)
			printf("[%llu] %d %s\n",
				get_time() - table->start_time, phil->id, str);
		else
		{
			printf("\x1B[32m[%llu] all phils done eating %u times\x1B[32m\n",
				get_time() - table->start_time, table->nu_times_eat);
			table->is_dead = 1;
		}
	}
	pthread_mutex_unlock(table->orator);
}

void	*set_death(t_phil *phil, t_table *table, u_int64_t rest)
{
	pthread_mutex_lock(table->orator);
	if (!table->is_dead)
	{
		phil->is_dead = 1;
		table->is_dead = phil->id;
		if (rest != 0)
			ft_usleep(rest);
		printf("\x1B[31m[%llu] %u is dead\x1B[31m\n",
			get_time() - table->start_time, phil->id);
	}
	pthread_mutex_unlock(table->orator);
	return (0);
}
