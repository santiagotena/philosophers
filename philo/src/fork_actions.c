/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:26:22 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/14 04:11:21 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
bool	grab_own_fork(t_philo *philo)
{
	bool				result;
	pthread_mutex_t		*forks_mutex;
	int					*forks;
	int					philo_id;

	forks_mutex = philo->param->forks_mutex;
	forks = philo->param->is_fork_taken;
	philo_id = philo->philo_id;
	// pthread_mutex_lock(&philo->param->read_write_mutex);
	pthread_mutex_lock(&forks_mutex[philo_id]);
	result = is_fork_available(forks[philo_id]); // DR
	// pthread_mutex_unlock(&forks_mutex[philo_id]);
	if (result)
	{
		// pthread_mutex_lock(&forks_mutex[philo_id]);
		forks[philo_id] = 1; // DR
		// pthread_mutex_unlock(&forks_mutex[philo_id]);
		take_fork(philo);
		result = true;
	}
	// pthread_mutex_unlock(&philo->param->read_write_mutex);
	return (result);
}

bool	grab_next_fork(t_philo *philo)
{
	bool				result;
	pthread_mutex_t		*forks_mutex;
	int					*forks;
	int					philo_id;
	int					next_philo_id;

	forks_mutex = philo->param->forks_mutex;
	forks = philo->param->is_fork_taken;
	philo_id = philo->philo_id;
	next_philo_id = philo->next_philo_id;
	result = false;
	// pthread_mutex_lock(&philo->param->read_write_mutex);
	pthread_mutex_lock(&forks_mutex[next_philo_id]);
	result = is_fork_available(forks[next_philo_id]); // DR
	// pthread_mutex_unlock(&forks_mutex[next_philo_id]);
	if (result)
	{
		// pthread_mutex_lock(&forks_mutex[next_philo_id]);
		forks[next_philo_id] = 1; // DR
		// pthread_mutex_unlock(&forks_mutex[next_philo_id]);
		take_fork(philo);
		result = true;
	}
	else
	{
		// pthread_mutex_lock(&forks_mutex[philo_id]);
		forks[philo_id] = 0; // DR
		pthread_mutex_unlock(&forks_mutex[philo_id]);
		result = false;
	}
	// pthread_mutex_unlock(&philo->param->read_write_mutex);
	return (result);
}
void	drop_forks(t_philo *philo)
{
	pthread_mutex_t		*forks_mutex;
	int					*forks;
	int					philo_id;
	int					next_philo_id;

	forks_mutex = philo->param->forks_mutex;
	forks = philo->param->is_fork_taken;
	philo_id = philo->philo_id;
	next_philo_id = philo->next_philo_id;
	
	// pthread_mutex_lock(&philo->param->read_write_mutex);
	// pthread_mutex_lock(&forks_mutex[philo_id]);
	forks[philo_id] = 0; // DR
	pthread_mutex_unlock(&forks_mutex[philo_id]);

	// pthread_mutex_lock(&forks_mutex[next_philo_id]);
	forks[next_philo_id] = 0; // DR
	pthread_mutex_unlock(&forks_mutex[next_philo_id]);
	// pthread_mutex_unlock(&philo->param->read_write_mutex);
}