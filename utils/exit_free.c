/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:12:30 by edolgun           #+#    #+#             */
/*   Updated: 2023/02/02 15:12:32 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	fault_exit(void)
{
	printf("Wrong arguman!!\n");
	return (1);
}

int	free_struct(t_philosoph *philo, pthread_mutex_t *mutex1, t_context *c)
{
	if (mutex1)
		free(mutex1);
	if (philo)
		free(philo);
	if (c)
		free(c);
	return (1);
}

void	dest_mutex(t_philosoph *philo)
{
	int	i;

	i = 0;
	while (i < philo->c->number_of_philosophers)
		pthread_mutex_destroy(&philo->forks[i++]);
	pthread_mutex_destroy(philo->printpriority);
}
