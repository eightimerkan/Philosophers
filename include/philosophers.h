/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:14:58 by edolgun           #+#    #+#             */
/*   Updated: 2023/02/02 17:15:35 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_context
{
	int				number_of_philosophers;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				total_ate;
	unsigned long	start_time;
}					t_context;

typedef struct s_philosoph
{
	int				id;
	int				ate;
	unsigned long	last_time_to_eat;
	int				*checkdead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*printpriority;
	t_context		*c;
}					t_philosoph;

int					ft_atoi(const char *str);
int					init_context(t_context *context, char **argv);
int					fault_exit(void);
int					free_struct(t_philosoph *philo, pthread_mutex_t *mutex1,
						t_context *c);
int					init_philos(t_philosoph *philos, t_context *context);
void				init_philos2(t_philosoph *ph, pthread_mutex_t *m1,
						pthread_mutex_t *m2, t_context *c);
unsigned long		first_time(void);
unsigned long		now_time(t_philosoph *philo);
void				dest_mutex(t_philosoph *philo);

void				*fst(void *philos);
void				create_threads(pthread_t *threads, t_philosoph *philos);
int					check(t_philosoph *philo);
void				print(t_philosoph *philo, char *status, int kill);
int					philo_wait(t_philosoph *philo, unsigned long wait_time);
void				all_free(t_philosoph *philo, t_context *context);
#endif
