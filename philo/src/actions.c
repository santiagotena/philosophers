/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:41:06 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/10 04:49:23 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{	
	unsigned long long	time;

	if (philo->param->is_philo_dead == 1)
		return ;
	time = get_time_in_ms() - philo->param->start_time;
	printf("%llu ms: %d has taken a fork\n", time, philo->philo_id);
}

void	eat(t_philo *philo)
{
	unsigned long long	time;

	if (philo->param->is_philo_dead == 1)
		return ;
	time = get_time_in_ms() - philo->param->start_time;
	printf("%llu ms: %d is eating\n", time, philo->philo_id);
	philo->time_last_meal = get_time_in_ms();
	philo->ts_must_eat--;
	philo_sleep(philo->param->time_to_eat, philo->param);
}

void	sleeping(t_philo *philo)
{
	unsigned long long	time;

	if (philo->param->is_philo_dead == 1)
		return ;
	time = get_time_in_ms() - philo->param->start_time;
	printf("%llu ms: %d is sleeping\n", time, philo->philo_id);
	philo_sleep(philo->param->time_to_sleep, philo->param);
}

void	think(t_philo *philo)
{
	unsigned long long	time;

	if (philo->param->is_philo_dead == 1)
		return ;
	time = get_time_in_ms() - philo->param->start_time;
	printf("%llu ms: %d is thinking\n", time, philo->philo_id);
}

void	die(t_philo *philo)
{
	unsigned long long	time;

	philo->param->is_philo_dead = 1;
	time = get_time_in_ms() - philo->param->start_time;
	printf("%llu ms: %d died\n", time, philo->philo_id);
}
