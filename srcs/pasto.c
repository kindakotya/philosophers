/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 21:54:13 by gmayweat          #+#    #+#             */
/*   Updated: 2021/07/25 03:01:10 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	aftereating(t_table *table, t_phil *phil)
{
	if (table->phils_eaten == table->nu_philo)
	{
		drop_forks(phil);
		orator_says(0, 0, table);
		return (1);
	}
	orator_says("went sleep", phil, table);
	drop_forks(phil);
	if (get_time() - phil->last_eating + table->time_sleep
		> table->time_die)
	{
		set_death(phil, table, table->time_die);
		return (1);
	}
	ft_usleep(table->time_sleep);
	orator_says("is thinking", phil, table);
	return (0);
}

static void	*sim_pasto(void *ph)
{
	t_table		*table;
	t_phil		*phil;

	phil = (t_phil *)ph;
	table = (t_table *)phil->table;
	phil->last_eating = table->start_time;
	while (1)
	{
		if (doctor(table))
			return (0);
		if (get_time() - phil->last_eating > table->time_die)
			return (set_death(phil, table, 0));
		if (table->time_eat > table->time_die || table->nu_philo == 1)
			return (set_death(phil, table, table->time_die));
		if (!eat(phil, table))
		{
			if (aftereating(table, phil))
				return (0);
		}
		else
			return (0);
	}
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
	table->start_time = get_time();
	while (i < table->nu_philo)
	{
		if (pthread_join(*(table->pthreads + i), NULL))
			return (1);
		++i;
	}
	return (0);
}
