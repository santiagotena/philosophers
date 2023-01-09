/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:41:06 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/09 20:10:09 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{	
	unsigned long long	time;
	
	// Check death
	time = get_time_in_ms() - philo->param->start_time;
	printf("%llu ms: %d has taken a fork\n", time, philo->philo_id);
}

void	eat(t_philo *philo)
{
	unsigned long long	time;
	
	// Check death
	time = get_time_in_ms() - philo->param->start_time;
	printf("%llu ms: %d is eating\n", time, philo->philo_id);
	// sleep
}

void	sleeping(t_philo *philo)
{
	unsigned long long	time;
	
	// Check death
	time = get_time_in_ms() - philo->param->start_time;
	printf("%llu ms: %d is sleeping\n", time, philo->philo_id);
	// sleep
}

void	think(t_philo *philo)
{
	unsigned long long	time;
	
	// Check death
	time = get_time_in_ms() - philo->param->start_time;
	printf("%llu ms: %d is thinking\n", time, philo->philo_id);
	// time to think cacl + sleep
}

void	die(t_philo *philo)
{
	unsigned long long	time;
	
	// Check death
	time = get_time_in_ms() - philo->param->start_time;
	printf("%llu ms: %d died\n", time, philo->philo_id);
}
