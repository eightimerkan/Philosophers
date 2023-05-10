/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:12:57 by edolgun           #+#    #+#             */
/*   Updated: 2023/02/02 15:12:58 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	check_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	init_context(t_context *context, char **argv)
{
	if (check_digit(argv))
	{
		printf("Wrong arguman just enter number please!!\n");
		return (1);
	}
	context->number_of_philosophers = ft_atoi(argv[1]);
	context->time_to_die = ft_atoi(argv[2]);
	context->time_to_eat = ft_atoi(argv[3]);
	context->time_to_sleep = ft_atoi(argv[4]);
	context->start_time = first_time();
	context->total_ate = 0;
	if (context->number_of_philosophers <= 0 || context->time_to_die <= 0 || \
		context->time_to_eat <= 0 || context->time_to_sleep <= 0)
		return (1);
	if (argv[5])
	{
		context->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		if (context->number_of_times_each_philosopher_must_eat <= 0)
			return (1);
	}
	else
		context->number_of_times_each_philosopher_must_eat = -1;
	return (0);
}

int	init_philos(t_philosoph *philos, t_context *context)
{
	pthread_mutex_t	*f;
	pthread_mutex_t	*pp;
	int				i;

	f = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* context->number_of_philosophers);
	i = 0;
	pp = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!philos || !f)
		return (free_struct(philos, f, context));
	while (i < context->number_of_philosophers)
	{
		if (pthread_mutex_init(&f[i], 0))
			return (free_struct(philos, f, context));
		i++;
	}
	if (pthread_mutex_init(pp, 0))
		return (free_struct(philos, f, context));
	init_philos2(philos, f, pp, context);
	return (0);
}

void	init_philos2(t_philosoph *ph, pthread_mutex_t *m1, pthread_mutex_t *m2,
		t_context *c)
{
	int	i;
	int	*checkdeads;

	i = 0;
	checkdeads = malloc(sizeof(int));
	*checkdeads = 0;
	while (i < c->number_of_philosophers)
	{
		ph[i].ate = 0;
		ph[i].id = i + 1;
		ph[i].forks = m1;
		ph[i].printpriority = m2;
		ph[i].c = c;
		ph[i].checkdead = checkdeads;
		ph[i].last_time_to_eat = first_time();
		i++;
	}
}
