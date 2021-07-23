/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:32:14 by gmayweat          #+#    #+#             */
/*   Updated: 2021/07/23 23:03:05 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_calloc(int n, int size)
{
	void	*mem;

	mem = malloc(n * size);
	if (!mem)
		return (0);
	memset(mem, '\0', n * size);
	return (mem);
}

u_int64_t	get_time(void)
{
	struct timeval	s_time;

	if (gettimeofday(&s_time, NULL))
		return (0);
	return (s_time.tv_sec * 1000000ull + s_time.tv_usec);
}

void	orator_says(char *str, t_phil *phil, t_table *table, u_int64_t time)
{
	u_int64_t	current_time;

	if (doctor(table))
		return ;
	pthread_mutex_lock(table->orator);
	current_time = get_time();
	if (!current_time)
		return ;
	printf("[%llu] %d %s\n",(current_time - time) / 1000, phil->id, str);
	pthread_mutex_unlock(table->orator);
}
// void	ft_usleep(u_int64_t t)
// {
// 	u_int64_t	current;

	
// }