/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:41:06 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/15 03:31:56 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{	
	unsigned long long	time;

	pthread_mutex_lock(&philo->param->msg_mutex);
	if (!are_all_alive(philo->param))
	{
		pthread_mutex_unlock(&philo->param->msg_mutex);
		return ;
	}
	time = get_time_in_ms() - philo->param->start_time;
	printf(ANSI_COLOR_YELLOW "%llu ms: %d has taken a fork\n" ANSI_COLOR_RESET, time, philo->philo_id);
	pthread_mutex_unlock(&philo->param->msg_mutex);
}

void	eat(t_philo *philo)
{
	unsigned long long	time;

	pthread_mutex_lock(&philo->param->msg_mutex);
	if (!are_all_alive(philo->param))
	{
		pthread_mutex_unlock(&philo->param->msg_mutex);
		return ;
	}
	time = get_time_in_ms() - philo->param->start_time;
	printf(ANSI_COLOR_GREEN "%llu ms: %d is eating\n" ANSI_COLOR_RESET, time, philo->philo_id);
	philo->ts_must_eat--;
	pthread_mutex_unlock(&philo->param->msg_mutex);
	pthread_mutex_lock(&philo->param->time_last_meal_mutex);
	philo->time_last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->param->time_last_meal_mutex);
	philo_sleep(philo->param->time_to_eat, philo->param);
}

void	sleeping(t_philo *philo)
{
	unsigned long long	time;

	pthread_mutex_lock(&philo->param->msg_mutex);
	if (!are_all_alive(philo->param))
	{
		pthread_mutex_unlock(&philo->param->msg_mutex);
		return ;
	}
	time = get_time_in_ms() - philo->param->start_time;
	printf(ANSI_COLOR_BLUE "%llu ms: %d is sleeping\n" ANSI_COLOR_RESET, time, philo->philo_id);
	pthread_mutex_unlock(&philo->param->msg_mutex);
	philo_sleep(philo->param->time_to_sleep, philo->param);
}

void	think(t_philo *philo)
{
	unsigned long long	time;
	unsigned long long	time_to_think;

	pthread_mutex_lock(&philo->param->msg_mutex);
	if (!are_all_alive(philo->param))
	{
		pthread_mutex_unlock(&philo->param->msg_mutex);
		return ;
	}
	time = get_time_in_ms() - philo->param->start_time;
	printf(ANSI_COLOR_MAGENTA "%llu ms: %d is thinking\n" ANSI_COLOR_RESET, time, philo->philo_id);
	pthread_mutex_unlock(&philo->param->msg_mutex);
	pthread_mutex_lock(&philo->param->time_last_meal_mutex);
	time_to_think = (philo->param->time_to_die - \
					(get_time_in_ms() - philo->time_last_meal) \
					- philo->param->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->param->time_last_meal_mutex);
	ft_sleep(time_to_think);
}

void	die(t_philo *philo)
{
	unsigned long long	time;
	
	// pthread_mutex_lock(&philo->param->msg_mutex);
	time = get_time_in_ms() - philo->param->start_time;
	printf(ANSI_COLOR_RED "%llu ms: %d died\n" ANSI_COLOR_RESET, time, philo->philo_id);
	// pthread_mutex_unlock(&philo->param->msg_mutex);
}
