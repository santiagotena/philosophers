/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:41:06 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/12 00:42:42 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{	
	unsigned long long	time;

	if (philo->param->is_philo_dead == 1)
		return ;
	pthread_mutex_lock(&philo->param->msg_mutex);
	time = get_time_in_ms() - philo->param->start_time;
	printf("%llu ms: %d has taken a fork\n", time, philo->philo_id);
	pthread_mutex_unlock(&philo->param->msg_mutex);
}

void	eat(t_philo *philo)
{
	unsigned long long	time;

	if (philo->param->is_philo_dead == 1)
		return ;
	pthread_mutex_lock(&philo->param->msg_mutex);
	time = get_time_in_ms() - philo->param->start_time;
	printf("%llu ms: %d is eating\n", time, philo->philo_id);
	philo->time_last_meal = get_time_in_ms();
	philo->ts_must_eat--;
	pthread_mutex_unlock(&philo->param->msg_mutex);
	philo_sleep(philo->param->time_to_eat, philo->param);
}

void	sleeping(t_philo *philo)
{
	unsigned long long	time;

	if (philo->param->is_philo_dead == 1)
		return ;
	pthread_mutex_lock(&philo->param->msg_mutex);
	time = get_time_in_ms() - philo->param->start_time;
	printf("%llu ms: %d is sleeping\n", time, philo->philo_id);
	pthread_mutex_unlock(&philo->param->msg_mutex);
	philo_sleep(philo->param->time_to_sleep, philo->param);
}

void	think(t_philo *philo)
{
	unsigned long long	time;
	unsigned long long	time_to_think;

	if (philo->param->is_philo_dead == 1)
		return ;
	pthread_mutex_lock(&philo->param->msg_mutex);
	time = get_time_in_ms() - philo->param->start_time;
	printf("%llu ms: %d is thinking\n", time, philo->philo_id);
	time_to_think = (philo->param->time_to_die - \
					(get_time_in_ms() - philo->time_last_meal) \
					- philo->param->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->param->msg_mutex);
	if (philo->param->is_times_must_eat == 0)
		return ;
	ft_sleep(time_to_think);
}

void	die(t_philo *philo)
{
	unsigned long long	time;

	pthread_mutex_lock(&philo->param->is_philo_dead_mutex);
	philo->param->is_philo_dead = 1; // Data race done
	pthread_mutex_unlock(&philo->param->is_philo_dead_mutex);
	pthread_mutex_lock(&philo->param->msg_mutex);
	time = get_time_in_ms() - philo->param->start_time;
	printf("%llu ms: %d died\n", time, philo->philo_id);
	pthread_mutex_unlock(&philo->param->msg_mutex);
}
