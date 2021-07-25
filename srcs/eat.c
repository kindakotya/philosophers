/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 19:13:06 by gmayweat          #+#    #+#             */
/*   Updated: 2021/07/25 02:59:44 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	take_forks(t_phil *phil, t_table *table)
{
	if (phil->id == table->nu_philo)
	{
		pthread_mutex_lock(phil->rigth);
		orator_says("has taken a fork", phil, table);
		pthread_mutex_lock(phil->left);
		orator_says("has taken a fork", phil, table);
	}
	else
	{
		pthread_mutex_lock(phil->left);
		orator_says("has taken a fork", phil, table);
		pthread_mutex_lock(phil->rigth);
		orator_says("has taken a fork", phil, table);
	}
	return (1);
}

int	drop_forks(t_phil *phil)
{
	pthread_mutex_unlock(phil->left);
	pthread_mutex_unlock(phil->rigth);
	return (1);
}

int	eat(t_phil *phil, t_table *table)
{
	take_forks(phil, table);
	orator_says("is eating", phil, table);
	if (get_time() - phil->last_eating + table->time_eat > table->time_die)
		return (set_death(phil, table, table->time_die - (get_time()
					- phil->last_eating)) || drop_forks(phil));
	ft_usleep(table->time_eat);
	phil->last_eating = get_time();
	if (table->nu_times_eat)
	{
		pthread_mutex_lock(table->orator);
		++phil->eat_times;
		if (phil->eat_times == table->nu_times_eat)
			++table->phils_eaten;
		pthread_mutex_unlock(table->orator);
	}
	return (0);
}
