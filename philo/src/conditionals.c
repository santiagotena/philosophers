/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditionals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:31:35 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/14 05:47:40 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	are_all_alive(t_param *param)
{
	bool	result;

	result = false;
	pthread_mutex_lock(&param->is_philo_dead_mutex);
	if (param->is_philo_dead == 0)
		result = true;
	pthread_mutex_unlock(&param->is_philo_dead_mutex);
	return (result);
}

bool	is_any_hungry(t_param *param)
{
	bool	result;

	result = false;
	pthread_mutex_lock(&param->hungry_philo_mutex);
	if (param->hungry_philo > 0)
		result = true;
	pthread_mutex_unlock(&param->hungry_philo_mutex);
	return (result);
}

bool	are_all_full(t_param *param)
{
	bool	result;

	result = false;
	pthread_mutex_lock(&param->hungry_philo_mutex);
	if (param->hungry_philo == 0)
		result = true;
	pthread_mutex_unlock(&param->hungry_philo_mutex);
	return (result);
}

bool	is_time_to_die(unsigned long long last_meal, t_philo *philo)
{
	bool	result;

	result = false;
	pthread_mutex_lock(&philo->param->time_to_die_mutex);
	if (last_meal >= philo->param->time_to_die)
		result = true;
	pthread_mutex_unlock(&philo->param->time_to_die_mutex);
	return (result);
}

bool	is_fork_available(int is_fork_taken)
{
	bool	result;

	result = false;
	if (is_fork_taken == 0)
		result = true;
	return (result);
}
