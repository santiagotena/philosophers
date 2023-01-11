/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:09:00 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/11 20:13:53 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_cont(t_philo *philo)
{
	// if (philo->philo_id % 2 == 1)
	// 	ft_sleep(15);
	while (philo->param->is_philo_dead == 0 && philo->param->hungry_philo > 0)
	{
		while (philo->param->is_philo_dead == 0 && philo->param->hungry_philo > 0)
		{
			if (grab_own_fork(philo) && grab_next_fork(philo))
			{
				take_fork(philo);
				eat(philo);
				drop_forks(philo);
				break ;
			}
			// else
			// 	ft_sleep(1);
		}
		sleeping(philo);
		think(philo);
		if (philo->param->is_times_must_eat && philo->ts_must_eat == 0)
			philo->param->hungry_philo--;
	}
}

void	*routine(void *args)
{
	t_philo		*philo;

	philo = (t_philo *)args;
	philo->time_last_meal = philo->param->start_time;
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
	while (param->is_philo_dead == 0 && param->hungry_philo > 0)
	{
		i = 1;
		while (i <= param->n_philo)
		{
			if (param->hungry_philo == 0)
				break ;
			last_meal = get_time_in_ms() - param->philos[i].time_last_meal;
			if (last_meal >= param->time_to_die)
			{
				die(&param->philos[i]);
				break ;
			}
			i++;
		}
	}
	return (NULL);
}
