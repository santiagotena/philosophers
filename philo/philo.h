/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:11:34 by stena-he          #+#    #+#             */
/*   Updated: 2022/12/29 20:15:09 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* Libraries */
//Threads Library
# include <pthread.h>

/* Structs */
//Input data 
typedef struct s_data
{
	int				argc;
	char			**argv;
	char			**envp;
	int				i;
	int				j;
}					t_data;

/* Functions */
// Pipe setup //
// int		pipes_setup(int argc, char **argv, char **envp);

// Execute commands //



#endif
