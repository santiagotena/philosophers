/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:09:00 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/13 01:17:51 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_cont(t_philo *philo)
{
	while (are_all_alive(philo->param) && is_any_hungry(philo->param))
	{
		while (are_all_alive(philo->param) && \
				is_any_hungry(philo->param))
		{
			if (grab_own_fork(philo) && grab_next_fork(philo))
			{
				take_fork(philo);
				eat(philo);
				drop_forks(philo);
				break ;
			}
			else
				ft_sleep(1);
		}
		sleeping(philo);
		think(philo);
		if (philo->param->is_times_must_eat && philo->ts_must_eat == 0)
		{
			// pthread_mutex_lock(&philo->param->hungry_philo_mutex);
			philo->param->hungry_philo--;
			// pthread_mutex_unlock(&philo->param->hungry_philo_mutex);
		}
	}
}

void	*routine(void *args)
{
	t_philo		*philo;

	philo = (t_philo *)args;
	pthread_mutex_lock(&philo->param->time_last_meal_mutex);
	philo->time_last_meal = philo->param->start_time;
	pthread_mutex_unlock(&philo->param->time_last_meal_mutex);
	routine_cont(philo);
	return (NULL);
}

void	*main_routine(void *args)
{
	int					i;
	unsigned long long	last_meal;
	t_param				*param;

	param = (t_param *)args;
	ft_sleep(param->time_to_die / 2);
	while (are_all_alive(param) && is_any_hungry(param))
	{
		i = 1;
		while (i <= param->n_philo)
		{
			if (are_all_full(param))
				break ;
			pthread_mutex_lock(&param->time_last_meal_mutex);
			last_meal = get_time_in_ms() - param->philos[i].time_last_meal;
			pthread_mutex_unlock(&param->time_last_meal_mutex);
			if (is_time_to_die(last_meal, &param->philos[i]))
			{
				pthread_mutex_lock(&param->is_philo_dead_mutex);
				param->is_philo_dead = 1;
				pthread_mutex_unlock(&param->is_philo_dead_mutex);
				die(&param->philos[i]);
				break ;
			}
			i++;
		}
	}
	return (NULL);
}
