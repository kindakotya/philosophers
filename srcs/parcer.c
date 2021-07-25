/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 22:54:14 by gmayweat          #+#    #+#             */
/*   Updated: 2021/07/24 23:08:23 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static u_int64_t	philosophers_atoi(const char *str)
{
	int			i;
	u_int64_t	num;

	i = 0;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + str[i++] - '0';
	if (str[i])
		return (0);
	return (num);
}

static int	create_philo(t_table *table, u_int32_t n)
{
	if (n != table->nu_philo - 1)
	{
		table->philos[n].rigth = malloc(sizeof(pthread_mutex_t));
		if (!table->philos[n].rigth)
			return (1);
		if (pthread_mutex_init(table->philos[n].rigth, NULL))
			return (1);
		if (n == 0)
		{
			table->philos[n].left = malloc(sizeof(pthread_mutex_t));
			if (!table->philos[n].left)
				return (1);
			if (pthread_mutex_init(table->philos[n].left, NULL))
				return (1);
		}
	}
	else
		table->philos[n].rigth = table->philos[0].left;
	if (n != 0)
		table->philos[n].left = table->philos[n - 1].rigth;
	table->philos[n].id = n + 1;
	table->philos[n].table = table;
	return (0);
}

static int	philos_alloc(t_table *table)
{
	u_int32_t	i;

	i = 0;
	table->philos = ft_calloc(table->nu_philo + 1, sizeof(t_phil));
	if (!table->philos)
		return (1);
	table->pthreads = ft_calloc(table->nu_philo, sizeof(pthread_t));
	if (!table->pthreads)
		return (1);
	while (i < table->nu_philo)
	{
		if (create_philo(table, i))
			return (1);
		++i;
	}
	return (0);
}

int	parcer_init(int ac, char **av, t_table *table)
{
	memset(table, 0, sizeof(t_table));
	table->nu_philo = philosophers_atoi(av[0]);
	table->time_die = philosophers_atoi(av[1]);
	table->time_eat = philosophers_atoi(av[2]);
	table->time_sleep = philosophers_atoi(av[3]);
	if (ac == 5)
		table->nu_times_eat = philosophers_atoi(av[4]);
	if (table->nu_philo == 0 || table->time_die == 0 || table->time_eat == 0
		|| table->time_sleep == 0 || (table->nu_times_eat == 0 && ac == 5))
		return (1);
	if (philos_alloc(table))
		return (1);
	table->start_time = get_time();
	table->orator = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!table->orator)
		return (1);
	if (pthread_mutex_init(table->orator, NULL))
		return (1);
	return (0);
}
