/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:58:15 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/10 21:38:16 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_philo		*philo;
	
	philo = (t_philo *)args;
	philo->time_last_meal = philo->param->start_time;
	if (philo->philo_id % 2 == 0)
		ft_sleep(1);
	while (philo->param->is_philo_dead == 0)
	{
		while (1)
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
			philo->param->hungry_philo--;
			break ;
		}
	}
	return (NULL);
}

void	*main_routine(void *args)
{
	int					i;
	unsigned long long	last_meal;
	t_param				*param;
	
	param = (t_param *)args;
	ft_sleep(param->time_to_die/2);
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

int		philosophers(t_param *param)
{
	int		i;
	
	// Initialize values //
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
	
	// Init mutexes //
	i = 1;
	while (i <= param->n_philo)
	{
		pthread_mutex_init(&param->philos->fork_lock, NULL);
		i++;
	}
	
	// Init threads //
	i = 1;
	param->start_time = get_time_in_ms();
    while (i < (param->n_philo + 1))
	{
        if (pthread_create(&param->th[i], NULL, &routine, &param->philos[i]) != 0)
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
	
	// Join threads //
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

	// Destroy mutex //
	i = 1;
	while (i < param->n_philo)
	{
		pthread_mutex_destroy(&param->philos->fork_lock);
		i++;
	}
	
	// Free stuff //
	free(param->th);
	free(param->philos);
    return (0);
}