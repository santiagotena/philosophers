/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:58:15 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/15 02:49:42 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_param *param)
{
	int		i;

	i = 0;
	while (i <= param->n_philo)
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
	while (i <= param->n_philo)
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
	while (i <= param->n_philo)
	{
		pthread_mutex_init(&param->forks_mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&param->msg_mutex, NULL);
	pthread_mutex_init(&param->time_last_meal_mutex, NULL);
	pthread_mutex_init(&param->time_to_die_mutex, NULL);
	pthread_mutex_init(&param->hungry_philo_mutex, NULL);
	pthread_mutex_init(&param->is_philo_dead_mutex, NULL);
	pthread_mutex_init(&param->death_check_mutex, NULL);
	return (0);
}

void	init_values(t_param *param)
{
	int		i;

	param->th = malloc(sizeof(pthread_t) * (param->n_philo + 1));
	param->philos = malloc(sizeof(t_philo) * (param->n_philo + 1));
	param->is_fork_taken = malloc(sizeof(int) * (param->n_philo + 1));
	param->forks_mutex = malloc(sizeof(pthread_mutex_t) * (param->n_philo + 1));
	param->hungry_philo = param->n_philo;
	i = 1;
	while (i <= param->n_philo)
	{
		param->philos[i].philo_id = i;
		if (i == param->n_philo)
			param->philos[i].next_philo_id = 1;
		else
			param->philos[i].next_philo_id = i + 1;
		param->philos[i].ts_must_eat = param->times_must_eat;
		param->is_fork_taken[i] = 0;
		param->philos[i].param = param;
		i++;
	}
}

int	philosophers(t_param *param)
{
	init_values(param);
	if (init_mutex(param) < 0)
		return (-1);
	if (init_threads(param) < 0)
		return (-1);
	if (join_threads(param) < 0)
		return (-1);
	if (destroy_mutex(param) < 0)
		return (-1);
	free_values(param);
	return (0);
}
