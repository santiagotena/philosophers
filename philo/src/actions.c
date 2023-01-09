/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:41:06 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/09 01:14:00 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{	
	printf("ms %d has taken a fork\n", philo->philo_id);

	// t_param		*param;
	// time_t		st;
	
	// param = philo->param;
	// st = param->start_time;
	// printf("%ld", param->start_time);
}

void	eat(t_philo *philo)
{
	printf("ms %d is eating\n", philo->philo_id);
}

void	sleeping(t_philo *philo)
{
	printf("ms %d is sleeping\n", philo->philo_id);
}

void	think(t_philo *philo)
{
	printf("ms %d is thinking\n", philo->philo_id);
}

void	die(t_philo *philo)
{
	printf("ms %d died\n", philo->philo_id);
}

// time_t		current_time;
// usleep(time_to_die * 1000);
// current_time = get_time_in_ms() - start_time;
// printf("%ld ms: %d has died\n", current_time, philo->philo_id);