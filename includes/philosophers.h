/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 22:46:12 by gmayweat          #+#    #+#             */
/*   Updated: 2021/07/24 23:05:25 by gmayweat         ###   ########.fr       */
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
	void			*table;
	u_int32_t		id;
	u_int64_t		last_eating;
	int				is_dead;
	u_int32_t		eat_times;
	pthread_mutex_t	*left;
	pthread_mutex_t	*rigth;
}				t_phil;

typedef struct s_table
{
	u_int32_t		nu_philo;
	u_int64_t		time_die;
	u_int64_t		time_eat;
	u_int64_t		time_sleep;
	u_int32_t		nu_times_eat;
	u_int64_t		phils_eaten;
	u_int64_t		start_time;
	int				is_dead;
	pthread_t		*pthreads;
	t_phil			*philos;
	pthread_mutex_t	*orator;
}				t_table;

int			parcer_init(int ac, char **av, t_table *args);
void		*ft_calloc(int n, int size);
u_int64_t	get_time(void);
int			doctor(t_table *table);
int			start_pasto(t_table *table);
int			eat(t_phil *phil, t_table *table);
void		philosophers_free(t_table *table);
void		ft_usleep(u_int64_t t);
void		orator_says(char *str, t_phil *phil, t_table *table);
int			drop_forks(t_phil *phil);
void		*set_death(t_phil *phil, t_table *table, u_int64_t rest);
#endif