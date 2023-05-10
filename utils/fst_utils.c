/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:12:41 by edolgun           #+#    #+#             */
/*   Updated: 2023/02/02 16:58:39 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print(t_philosoph *philo, char *status, int kill)
{
	pthread_mutex_lock(philo->printpriority);
	if (!*philo->checkdead)
	{
		printf("%lums %d %s\n", now_time(philo), philo->id, status);
		if (kill)
			*philo->checkdead = 1;
	}
	pthread_mutex_unlock(philo->printpriority);
	check(philo);
}

int	check(t_philosoph *philo)
{
	if (philo->c->total_ate == philo->c->number_of_philosophers)
		return (1);
	pthread_mutex_lock(philo->printpriority);
	if (*philo->checkdead)
	{
		pthread_mutex_unlock(philo->printpriority);
		return (1);
	}
	pthread_mutex_unlock(philo->printpriority);
	if (first_time() - philo->last_time_to_eat > \
		philo->c->time_to_die)
	{
		print(philo, "died", 1);
		return (1);
	}
	return (0);
}

int	philo_wait(t_philosoph *philo, unsigned long wait_time)
{
	unsigned long	time;

	time = first_time();
	while (first_time() - time < wait_time)
	{
		if (check(philo))
			return (1);
		usleep(100);
	}
	return (0);
}
