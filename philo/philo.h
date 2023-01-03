/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:11:34 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/03 23:37:30 by stena-he         ###   ########.fr       */
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
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
}					t_param;

typedef struct s_philo
{
	int				number_of_philosophers;
}					t_philo;

/* Functions */
// Pipe setup //
// int		pipes_setup(int argc, char **argv, char **envp);

// Utils //
int		ft_atoi(const char *str);

#endif
