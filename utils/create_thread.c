/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:12:24 by edolgun           #+#    #+#             */
/*   Updated: 2023/02/02 15:54:51 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	create_threads(pthread_t *threads, t_philosoph *philos)
{
	int	i;

	i = 0;
	while (i < philos->c->number_of_philosophers)
	{
		pthread_create(&threads[i], NULL, fst, &philos[i]);
		i++;
		usleep(100);
	}
	i = 0;
	while (i < philos->c->number_of_philosophers)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}
