/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 22:42:57 by gmayweat          #+#    #+#             */
/*   Updated: 2021/07/23 22:19:35 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;
	t_table nan;

	if (argc < 5 || argc > 6)
	{
		printf("Error: %d arguments is not required\n", argc);
		return (1);
	}
	if (parcer_init(argc - 1, ++argv, &table))
	{
		printf("Error: arguments is not valid\n");
		return (1);
	}
	start_pasto(&table);
	philosophers_free(&table);
	nan.is_dead = 1;
	table = nan;
	// getchar();
	return (0);
}
