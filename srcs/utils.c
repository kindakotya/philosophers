/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:32:14 by gmayweat          #+#    #+#             */
/*   Updated: 2021/07/22 22:26:22 by gmayweat         ###   ########.fr       */
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

// void	ft_usleep(u_int64_t t)
// {
// 	u_int64_t	current;

	
// }