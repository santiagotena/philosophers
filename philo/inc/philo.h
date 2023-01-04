/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:11:34 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/04 20:13:39 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* Libraries */
//Threads Library
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

/* Structs */
//Parameters 
typedef struct s_param
{
	int					n_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					times_must_eat;

	int					i;
	struct t_philo 		*philos;
	pthread_t			*th;
	pthread_mutex_t		*mutex;
}					t_param;

typedef struct s_philo
{
	int					n_philo;
	struct t_param 		*param;
}						t_philo;

/* Functions */
// Parse Arguments //
int		parse_args(int argc, char **argv, t_param *param);

// Philosophers //
int		philosophers(t_param *param);

#endif
