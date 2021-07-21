/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 22:54:14 by gmayweat          #+#    #+#             */
/*   Updated: 2021/07/21 23:17:20 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

u_int32_t	philosophers_atoi(const char *str)
{
	int			i;
	u_int32_t	num;

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

int	parcer_init(int ac, char **av, t_args *args)
{
	memset(args, 0, sizeof(t_args));
	args->nu_philo = philosophers_atoi(av[0]);
	args->time_die = philosophers_atoi(av[1]);
	args->time_eat = philosophers_atoi(av[2]);
	args->time_sleep = philosophers_atoi(av[3]);
	if (ac == 5)
		args->nu_times_eat = philosophers_atoi(av[4]);
	if (args->nu_philo == 0 || args->time_die == 0 || args->time_eat == 0
		|| args->time_sleep == 0 || (args->nu_times_eat == 0 && ac == 5))
		return (1);
	return (0);
}
