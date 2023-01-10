/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:11:34 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/10 01:52:44 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* Libraries */
//Threads Library
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

/* Structs */
//Parameters 
typedef struct s_philo
{
	struct s_param		*param;
	int					philo_id;
	int					ts_must_eat;

	unsigned long long	time_last_meal;
	
	pthread_mutex_t		*msg_mutex; // Unsure
}						t_philo;

typedef struct s_param
{
	int					n_philo;
	unsigned long long	time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					times_must_eat;
	int					is_times_must_eat;
	unsigned long long	start_time;

	t_philo				*philos;
	pthread_t			*th;
	pthread_mutex_t		*mutex; // Unsure

	int					is_philo_dead;
}						t_param;

/* Functions */
// Parse Arguments //
int					parse_args(int argc, char **argv, t_param *param);

// Philosophers //
int					philosophers(t_param *param);

// Sole Philosopher //
void				sole_philo(int time_to_die);

// Actions //
void				take_fork(t_philo *philo);
void				eat(t_philo *philo);
void				sleeping(t_philo *philo);
void				think(t_philo *philo);
void				die(t_philo *philo);

// Utils //
unsigned long long	get_time_in_ms(void);
void				ft_sleep(int ms);
void				philo_sleep(unsigned long long sleep_time, t_param *param);

#endif
