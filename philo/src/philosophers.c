/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:58:15 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/10 04:50:53 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// pthread_mutex_t	mutex; // Delete

void	*routine(void *args)
{
	t_philo		*philo;
	
	philo = (t_philo *)args;
	philo->time_last_meal = philo->param->start_time;
	if (philo->philo_id % 2 == 0)
		ft_sleep(1);
	while (philo->param->is_philo_dead == 0)
	{
		// pthread_mutex_lock(&mutex); // Delete
		// pthread_mutex_lock(&mutex); // Delete
		take_fork(philo);
		eat(philo);
		// pthread_mutex_unlock(&mutex); // Delete
		// pthread_mutex_unlock(&mutex); // Delete
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
	param->mutex = malloc(sizeof(pthread_mutex_t) * (param->n_philo + 1));
	param->philos = malloc(sizeof(t_philo) * param->n_philo);
	param->hungry_philo = param->n_philo;
	
	i = 1;
	while (i <= param->n_philo)
	{
		param->philos[i].philo_id = i;
		param->philos[i].ts_must_eat = param->times_must_eat;
		param->philos[i].param = param;
		i++;
	}
	
	// Init mutexes //
	i = 0;
	while (i < (param->n_philo + 1))
		pthread_mutex_init(&param->mutex[i++], NULL);
	// pthread_mutex_init(&mutex, NULL); // Delete
	
	
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
	i = 0; // Must equal 0
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
	i = 0;
	while (i < (param->n_philo + 1))
		pthread_mutex_destroy(&param->mutex[i++]);
	// pthread_mutex_destroy(&mutex); // Delete
	
	// Free stuff //
	free(param->th);
	free(param->mutex);
	free(param->philos);
    return (0);
}