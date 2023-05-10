/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:13:03 by edolgun           #+#    #+#             */
/*   Updated: 2023/02/02 15:33:56 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

unsigned long	first_time(void)
{
	struct timeval	time;
	unsigned long	sec;
	unsigned long	macrosec;
	unsigned long	resultmicrosecond;

	gettimeofday(&time, NULL);
	sec = time.tv_sec * 1000;
	macrosec = time.tv_usec / 1000;
	resultmicrosecond = sec + macrosec;
	return (resultmicrosecond);
}

unsigned long	now_time(t_philosoph *philo)
{
	return (first_time() - philo->c->start_time);
}
