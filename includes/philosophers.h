/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 22:46:12 by gmayweat          #+#    #+#             */
/*   Updated: 2021/07/21 23:16:42 by gmayweat         ###   ########.fr       */
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

typedef struct s_args
{
	u_int32_t	nu_philo;
	u_int32_t	time_die;
	u_int32_t	time_eat;
	u_int32_t	time_sleep;
	u_int32_t	nu_times_eat;
}				t_args;

int	parcer_init(int ac, char **av, t_args *args);

#endif