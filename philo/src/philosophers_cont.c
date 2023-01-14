/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_cont.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:11:00 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/14 04:34:37 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_values(t_param *param)
{
	free(param->th);
	free(param->philos);
	free(param->forks_mutex);
}

int	destroy_mutex(t_param *param)
{
	int		i;

	i = 1;
	while (i <= param->n_philo)
	{
		// pthread_mutex_destroy(&param->philos[i].fork_lock);
		pthread_mutex_destroy(&param->forks_mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&param->msg_mutex);
	pthread_mutex_destroy(&param->time_last_meal_mutex);
	pthread_mutex_destroy(&param->time_to_die_mutex);
	pthread_mutex_destroy(&param->hungry_philo_mutex);
	pthread_mutex_destroy(&param->is_philo_dead_mutex);
	pthread_mutex_destroy(&param->read_write_mutex);
	pthread_mutex_destroy(&param->shared_fork_mutex);
	pthread_mutex_destroy(&param->grab_drop_mutex);
	// pthread_mutex_destroy(&param->own_fork_mutex);
	// pthread_mutex_destroy(&param->next_fork_mutex);
	// pthread_mutex_destroy(&param->is_fork_taken_mutex);
	return (0);
}
