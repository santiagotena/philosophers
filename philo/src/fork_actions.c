/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:26:22 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/10 18:03:53 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		grab_own_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_lock);
	if (philo->is_fork_taken == 0)
	{
		philo->is_fork_taken = 1;
		pthread_mutex_unlock(&philo->fork_lock);
		return (0);
	}
	else
	{	
		pthread_mutex_unlock(&philo->fork_lock);
		return (-1);
	}
}

// int		grab_next_fork(t_philo *philo)
// {
// 	t_philo		*philo;
	
	
// 	pthread_mutex_lock(&philo->fork_lock);
// 	if (&philo->is_fork_taken == 0)
// 	{
// 		philo->is_fork_taken = 1;
// 		pthread_mutex_unlock(&philo->fork_lock);
// 		return (0);
// 	}
// 	else
// 	{	
// 		pthread_mutex_unlock(&philo->fork_lock);
// 		return (-1);
// 	}
// }

// void	drop_forks(t_philo *philo)
// {

// }
