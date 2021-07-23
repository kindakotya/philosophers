/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 21:54:13 by gmayweat          #+#    #+#             */
/*   Updated: 2021/07/23 23:28:41 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	doctor(t_table *table)
{
	pthread_mutex_lock(table->orator);
	if (table->is_dead)
	{
		pthread_mutex_unlock(table->orator);
		return (1);
	}
	pthread_mutex_unlock(table->orator);
	return (0);
}

void	*set_death(t_phil *phil, t_table *table, u_int64_t time)
{
	pthread_mutex_lock(table->orator);
	phil->is_dead = 1;
	table->is_dead = phil->id;
	printf("[%llu] %u is dead\n", (get_time() - time) / 1000, phil->id);
	pthread_mutex_unlock(table->orator);
	return (0);
}

void	*sim_pasto(void *ph)
{
	t_table	*table;
	t_phil		*phil;
	u_int64_t	time;
	int			meal;

	phil = (t_phil *)ph;
	table = (t_table *)phil->table;
	time = get_time();
	phil->last_eating = time;
	while (1)
	{
		if (doctor(table))
			return (0);
		if (table->time_eat > table->time_die
			|| get_time() - phil->last_eating > table->time_die)
			return (set_death(phil, table, time));
		meal = eat(phil, table, time);
		if (meal == -1)
		{
			printf("Error detected\n");
			return ((void *)1);
		}
		if (table->phils_eaten == table->nu_philo)
			return (0);
		if (!meal)
		{
			if (get_time() - phil->last_eating + table->time_sleep
				> table->time_die)
				return (set_death(phil, table, time));
			orator_says("went sleep", phil, table, time);
			usleep(table->time_sleep);
		}
	}
	return (0);
}

int	start_pasto(t_table *table)
{
	u_int32_t	i;

	i = 0;
	while (i < table->nu_philo)
	{
		usleep(200);
		if (pthread_create(table->pthreads + i, NULL,
				&sim_pasto, table->philos + i))
			return (1);
		++i;
	}
	i = 0;
	while (i < table->nu_philo)
	{
		if (pthread_join(*(table->pthreads + i), NULL))
			return (1);
		++i;
	}
	return (0);
}
