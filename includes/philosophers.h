/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 22:46:12 by gmayweat          #+#    #+#             */
/*   Updated: 2021/07/22 23:16:00 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_phil
{
	void		*table;
	u_int32_t	id;
	u_int64_t	last_eating;
	int			is_dead;
	u_int32_t	eat_times;
	pthread_mutex_t	*left;
	pthread_mutex_t	*rigth;
}				t_phil;

typedef struct s_args
{
	u_int32_t	nu_philo;
	u_int64_t	time_die;
	u_int64_t	time_eat;
	u_int64_t	time_sleep;
	u_int32_t	nu_times_eat;
	u_int64_t	start_time;
	pthread_t	*pthreads;
	t_phil		*philos;
}				t_args;

int	parcer_init(int ac, char **av, t_args *args);
void	*ft_calloc(int n, int size);
u_int64_t	get_time(void);
#endif