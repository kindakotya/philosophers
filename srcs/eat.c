/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 19:13:06 by gmayweat          #+#    #+#             */
/*   Updated: 2021/07/23 23:02:56 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

int	take_forks(t_phil *phil)
{
	if (phil->id % 2 == 0)
	{
		pthread_mutex_lock(phil->rigth);
		pthread_mutex_lock(phil->left);
	}
	else
	{
		pthread_mutex_lock(phil->left);
		pthread_mutex_lock(phil->rigth);
	}
	return (1);
}

int	drop_forks(t_phil *phil)
{
	pthread_mutex_unlock(phil->left);
	pthread_mutex_unlock(phil->rigth);
	return (1);
}

int	eat(t_phil *phil, t_table *table, u_int64_t time)
{
	u_int64_t	current_time;

	if (take_forks(phil))
		orator_says("has taken a fork", phil, table, time);
	current_time = get_time();
	if (!current_time)
		return (-1);
	orator_says("is eating", phil, table, time);
	usleep(table->time_eat);
	drop_forks(phil);
	phil->last_eating = get_time();
	if (phil->last_eating == 0)
		return (-1);
	if (table->nu_times_eat)
	{
		++phil->eat_times;
		if (phil->eat_times == table->nu_times_eat)
			++table->phils_eaten;
	}
	return (0);
}
