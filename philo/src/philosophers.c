/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:58:15 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/11 01:26:20 by stena-he         ###   ########.fr       */
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

int	join_threads(t_param *param)
{
	int		i;

	i = 0;
	while (i < (param->n_philo + 1))
	{
		if (pthread_join(param->th[i], NULL) != 0)
		{
			write(2, "Failed to join thread\n", 23);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	init_threads(t_param *param)
{
	int		i;

	i = 1;
	param->start_time = get_time_in_ms();
	while (i < (param->n_philo + 1))
	{
		if (pthread_create(&param->th[i], NULL, \
			&routine, &param->philos[i]) != 0)
		{
			write(2, "Failed to create thread\n", 25);
			return (-1);
		}
		i++;
	}
	if (pthread_create(&param->th[0], NULL, &main_routine, param) != 0)
	{
		write(2, "Failed to create thread\n", 25);
		return (-1);
	}
	return (0);
}

int	init_mutex(t_param *param)
{
	int		i;

	i = 1;
	while (i++ <= param->n_philo)
		pthread_mutex_init(&param->philos->fork_lock, NULL);
	pthread_mutex_init(&param->msg_mutex, NULL);
	return (0);
}

void	init_values(t_param *param)
{
	int		i;

	param->th = malloc(sizeof(pthread_t) * (param->n_philo + 1));
	param->philos = malloc(sizeof(t_philo) * param->n_philo);
	param->hungry_philo = param->n_philo;
	i = 1;
	while (i <= param->n_philo)
	{
		param->philos[i].philo_id = i;
		param->philos[i].ts_must_eat = param->times_must_eat;
		param->philos[i].is_fork_taken = 0;
		param->philos[i].param = param;
		i++;
	}
}

int	philosophers(t_param *param)
{
	init_values(param);
	if (init_threads(param) < 0)
		return (-1);
	if (init_mutex(param) < 0)
		return (-1);
	if (join_threads(param) < 0)
		return (-1);
	if (destroy_mutex(param) < 0)
		return (-1);
	free_values(param);
	return (0);
}
