/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:12:47 by edolgun           #+#    #+#             */
/*   Updated: 2023/02/02 17:05:44 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	eat(t_philosoph *philo)
{
	if (check(philo))
		return ;
	pthread_mutex_lock(&philo->forks[philo->id - 1]);
	print(philo, "has taken a fork", 0);
	pthread_mutex_lock(&philo->forks[philo->id
		% philo->c->number_of_philosophers]);
	print(philo, "has taken a fork", 0);
	print(philo, "is eating", 0);
	pthread_mutex_lock(philo->printpriority);
	philo->ate++;
	if (philo->ate == philo->c->number_of_times_each_philosopher_must_eat)
		philo->c->total_ate++;
	philo->last_time_to_eat = first_time();
	pthread_mutex_unlock(philo->printpriority);
	philo_wait(philo, philo->c->time_to_eat);
	if (check(philo))
		return ;
}

void	p_sleep(t_philosoph *philo)
{
	pthread_mutex_unlock(&philo->forks[philo->id - 1]);
	pthread_mutex_unlock(&philo->forks[philo->id
		% philo->c->number_of_philosophers]);
	if (check(philo))
		return ;
	print(philo, "is sleeping", 0);
	philo_wait(philo, philo->c->time_to_sleep);
}

void	think(t_philosoph *philo)
{
	if (check(philo))
		return ;
	print(philo, "is thinking", 0);
}

void	*fst(void *philos)
{
	t_philosoph	*philo;

	philo = (t_philosoph *)philos;
	if (philo->c->number_of_philosophers == 1 && !check(philo))
	{
		if (pthread_mutex_lock(&philo->forks[philo->id - 1]))
			return (NULL);
		print(philo, " has taken a fork", 0);
		while (!check(philo))
		{
		}
		pthread_mutex_unlock(&philo->forks[philo->id - 1]);
	}
	else
	{
		while (1)
		{
			if (check(philo))
				break ;
			eat(philo);
			p_sleep(philo);
			think(philo);
		}
	}
	return (0);
}

/*
void	leavephilo(t_philosoph *philo, t_context *context)
{
	int	i;

	i = 0;
	while (1)
	{
		if (philo[i].c->total_ate == philo[i].c->number_of_philosophers)
		{
			dest_mutex(philo);
			free_struct(philo, philo->forks, context);
			return ;
		}
		if (first_time() - philo[i].last_time_to_eat
			> (unsigned long)context->time_to_die)
		{
			usleep(100);
			pthread_mutex_lock(philo->printpriority);
			printf("%lums	%d died", now_time(philo), philo->id);
			dest_mutex(philo);
			free_struct(philo, philo->forks, context);
			return ;
		}
		i = (i + 1) % context->number_of_philosophers;
		usleep(500);
	}
}
*/