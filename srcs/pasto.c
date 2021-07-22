/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 21:54:13 by gmayweat          #+#    #+#             */
/*   Updated: 2021/07/22 23:16:50 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	doctor(t_phil *phil, t_args *args)
{
	
}

void	sim_pasto(t_phil *phil)
{
	t_args	*args;

	args = (t_args *)phil->table;
	while (1)
	{
		if (doctor(phil, args))
			return ;
	}
}

int	start_pasto(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->nu_philo)
	{
		usleep(300);
		if (pthread_create(args->pthreads + i, NULL,
				sim_pasto, args->philos + i))
			return (1);
		++i;
	}
}
