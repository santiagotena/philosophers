/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:11:34 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/15 03:36:27 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

/* Libraries */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>

/* Structs */
typedef struct s_philo
{
	struct s_param		*param;
	int					philo_id;
	int					next_philo_id;
	int					ts_must_eat;
	unsigned long long	time_last_meal;
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
	pthread_t			*th;
	t_philo				*philos;
	int					*is_fork_taken;
	pthread_mutex_t		*forks_mutex;
	pthread_mutex_t		msg_mutex;
	pthread_mutex_t		time_last_meal_mutex;
	pthread_mutex_t		time_to_die_mutex;
	pthread_mutex_t		hungry_philo_mutex;
	pthread_mutex_t		is_philo_dead_mutex;
	int					is_philo_dead;
	int					hungry_philo;
}						t_param;

/* Functions */
// Parse Arguments //
int					parse_args(int argc, char **argv, t_param *param);

// Philosophers //
int					philosophers(t_param *param);

// Philosopers Continued //
int					destroy_mutex(t_param *param);
void				free_values(t_param *param);

// Sole Philosopher //
void				sole_philo(int time_to_die);

// Routines //
void				*routine(void *args);
void				*main_routine(void *args);

// Actions //
void				take_fork(t_philo *philo);
void				eat(t_philo *philo);
void				sleeping(t_philo *philo);
void				think(t_philo *philo);
void				die(t_philo *philo);

// Fork Actions //
bool				grab_own_fork(t_philo *philo);
bool				grab_next_fork(t_philo *philo);
void				drop_forks(t_philo *philo);

// Conditionals //
bool				are_all_alive(t_param *param);
bool				is_any_hungry(t_param *param);
bool				are_all_full(t_param *param);
bool				is_time_to_die(unsigned long long last_meal, \
						t_philo *philo);
bool				is_fork_available(int is_fork_taken);

// Utils //
unsigned long long	get_time_in_ms(void);
void				ft_sleep(int ms);
void				philo_sleep(unsigned long long sleep_time, t_param *param);

#endif
