/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:13:07 by edolgun           #+#    #+#             */
/*   Updated: 2023/02/02 17:14:42 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	main(int argc, char **argv)
{
	t_context	*context;
	t_philosoph	*philos;
	pthread_t	*threads;

	if (!(argc == 5 || argc == 6))
		return (fault_exit());
	context = (t_context *)malloc(sizeof(t_context));
	if (init_context(context, argv))
		return (free_struct(0, 0, context));
	philos = (t_philosoph *)malloc(sizeof(t_philosoph)
			* context->number_of_philosophers);
	if (init_philos(philos, context))
		return (1);
	threads = (pthread_t *)malloc(sizeof(pthread_t)
			* context->number_of_philosophers);
	create_threads(threads, philos);
	all_free(philos, context);
	return (0);
}
