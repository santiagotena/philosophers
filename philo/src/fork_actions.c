/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:26:22 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/10 22:01:06 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	grab_own_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_lock);
	if (philo->is_fork_taken == 0)
	{
		philo->is_fork_taken = 1;
		pthread_mutex_unlock(&philo->fork_lock);
		return (true);
	}
	else
	{	
		pthread_mutex_unlock(&philo->fork_lock);
		return (false);
	}
}

bool	grab_next_fork(t_philo *philo)
{
	t_philo		*philo_next;
	int			philo_id;

	philo_id = philo->philo_id;
	if (philo_id == philo->param->n_philo)
		philo_next = &philo->param->philos[1];
	else
		philo_next = &philo->param->philos[philo_id + 1];
	pthread_mutex_lock(&philo_next->fork_lock);
	if (philo_next->is_fork_taken == 0)
	{
		philo_next->is_fork_taken = 1;
		pthread_mutex_unlock(&philo_next->fork_lock);
		return (true);
	}
	else
	{	
		pthread_mutex_lock(&philo->fork_lock);
		philo->is_fork_taken = 0;
		pthread_mutex_unlock(&philo->fork_lock);
		pthread_mutex_unlock(&philo_next->fork_lock);
		return (false);
	}
}

void	drop_forks(t_philo *philo)
{
	t_philo		*philo_next;
	int			philo_id;

	philo_id = philo->philo_id;
	if (philo_id == philo->param->n_philo)
		philo_next = &philo->param->philos[1];
	else
		philo_next = &philo->param->philos[philo_id + 1];
	pthread_mutex_lock(&philo->fork_lock);
	philo->is_fork_taken = 0;
	pthread_mutex_unlock(&philo->fork_lock);
	philo_next->is_fork_taken = 0;
	pthread_mutex_lock(&philo_next->fork_lock);
}
