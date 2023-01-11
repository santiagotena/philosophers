/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_cont.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:11:00 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/11 23:11:30 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_values(t_param *param)
{
	free(param->th);
	free(param->philos);
}

int	destroy_mutex(t_param *param)
{
	int		i;

	i = 1;
	while (i < param->n_philo)
	{
		pthread_mutex_destroy(&param->philos->fork_lock);
		i++;
	}
	pthread_mutex_destroy(&param->msg_mutex);
	return (0);
}
