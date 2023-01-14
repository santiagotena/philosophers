/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:26:22 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/14 19:58:29 by stena-he         ###   ########.fr       */
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
	pthread_mutex_lock(&philo->param->forks_mutex[philo_id]);
	result = is_fork_available(forks[philo_id]); // DR 25
	if (result)
	{
		forks[philo_id] = 1;
		take_fork(philo);
		result = true;
	}
	else
		pthread_mutex_unlock(&philo->param->forks_mutex[philo_id]);
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
	pthread_mutex_lock(&philo->param->forks_mutex[next_philo_id]);
	result = is_fork_available(forks[next_philo_id]);
	if (result)
	{
		forks[next_philo_id] = 1; // DR 25
		take_fork(philo);

		result = true;
	}
	else
	{
		pthread_mutex_unlock(&philo->param->forks_mutex[next_philo_id]);
		forks[philo_id] = 0;
		pthread_mutex_unlock(&philo->param->forks_mutex[philo_id]);
		result = false;
	}
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
	

	forks[next_philo_id] = 0;
	pthread_mutex_unlock(&philo->param->forks_mutex[next_philo_id]);

	forks[philo_id] = 0; // DR
	pthread_mutex_unlock(&philo->param->forks_mutex[philo_id]);
}