/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:41:06 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/09 18:30:17 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{	
	// unsigned long long	time1;
	
	// time = 0; 
	// time = get_time_in_ms() - philo->param->start_time;
	// printf("%llu", get_time_in_ms());
	printf("%llu ms: %d has taken a fork\n", get_time_in_ms() - philo->param->start_time, philo->philo_id);
}

void	eat(t_philo *philo)
{
	time_t	time;
	
	time = 0; // current_time = get_time_in_ms() - start_time;
	printf("%ld ms: %d is eating\n", time, philo->philo_id);
	// sleep
}

void	sleeping(t_philo *philo)
{
	time_t	time;
	
	time = 0; // current_time = get_time_in_ms() - start_time;
	printf("%ld ms: %d is sleeping\n", time, philo->philo_id);
	// sleep
}

void	think(t_philo *philo)
{
	time_t	time;
	
	time = 0; // current_time = get_time_in_ms() - start_time;
	printf("%ld ms: %d is thinking\n", time, philo->philo_id);
	// time to think cacl + sleep
}

void	die(t_philo *philo)
{
	time_t	time;
	
	time = 0; // current_time = get_time_in_ms() - start_time;
	printf("%ld ms: %d died\n", time, philo->philo_id);
}
