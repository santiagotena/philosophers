/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_cont.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:11:00 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/15 04:38:58 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_values(t_param *param)
{
	free(param->th);
	free(param->philos);
	free(param->is_fork_taken);
	free(param->forks_mutex);
}

int	destroy_mutex(t_param *param)
{
	int		i;

	i = 1;
	while (i <= param->n_philo)
	{
		pthread_mutex_destroy(&param->forks_mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&param->msg_mutex);
	pthread_mutex_destroy(&param->time_last_meal_mutex);
	pthread_mutex_destroy(&param->time_to_die_mutex);
	pthread_mutex_destroy(&param->hungry_philo_mutex);
	pthread_mutex_destroy(&param->is_philo_dead_mutex);
	return (0);
}
