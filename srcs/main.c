/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 22:42:57 by gmayweat          #+#    #+#             */
/*   Updated: 2021/07/21 23:19:30 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc < 5 || argc > 6)
	{
		printf("Error: %d arguments is not required\n", argc);
		return (1);
	}
	if (parcer_init(argc - 1, ++argv, &args))
	{
		printf("Error: arguments is not valid\n");
		return (1);
	}
	return (0);
}
