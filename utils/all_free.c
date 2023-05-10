/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:11:35 by edolgun           #+#    #+#             */
/*   Updated: 2023/02/02 17:05:50 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	all_free(t_philosoph *philo, t_context *context)
{
	int	i;

	i = 0;
	while (i < context->number_of_philosophers)
	{
		pthread_mutex_destroy(&philo->forks[i++]);
	}
	pthread_mutex_destroy(philo->printpriority);
	free(philo->c);
	free(philo->checkdead);
	free(philo->printpriority);
	free(philo->forks);
	free(philo);
}
