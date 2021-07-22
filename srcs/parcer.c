/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 22:54:14 by gmayweat          #+#    #+#             */
/*   Updated: 2021/07/22 22:47:39 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

u_int64_t	philosophers_atoi(const char *str)
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

int	create_philo(t_args *args, u_int32_t n)
{
	if (n != args->nu_philo - 1)
	{
		if (pthread_mutex_init(args->philos[n].rigth, NULL))
			return (1);
		if (n == 0)
		{
			if (pthread_mutex_init(args->philos[n].left, NULL))
				return (1);
		}
	}
	else
		args->philos[n].rigth = args->philos[0].left;
	if (n != 0)
		args->philos[n].left = args->philos[n - 1].rigth;
	args->philos[n].id = n + 1;
	args->philos[n].table = args;
	return (0);
}

int	philos_alloc(t_args *args)
{
	u_int32_t	i;

	i = 0;
	args->philos = ft_calloc(args->nu_philo + 1, sizeof(t_phil));
	if (!args->philos)
		return (1);
	args->pthreads = ft_calloc(args->nu_philo, sizeof(pthread_t));
	if (!args->pthreads)
		return (1);
	while (i < args->nu_philo)
	{
		if (create_philo(args, i))
			return (1);
		++i;
	}
	return (0);
}

int	parcer_init(int ac, char **av, t_args *args)
{
	memset(args, 0, sizeof(t_args));
	args->nu_philo = philosophers_atoi(av[0]);
	args->time_die = philosophers_atoi(av[1]) * 1000;
	args->time_eat = philosophers_atoi(av[2]) * 1000;
	args->time_sleep = philosophers_atoi(av[3]) * 1000;
	if (ac == 5)
		args->nu_times_eat = philosophers_atoi(av[4]);
	if (args->nu_philo == 0 || args->time_die == 0 || args->time_eat == 0
		|| args->time_sleep == 0 || (args->nu_times_eat == 0 && ac == 5))
		return (1);
	if (philos_alloc(args))
		return (1);
	args->start_time = get_time();
	if (!args->start_time)
		return (1);
	return (0);
}
