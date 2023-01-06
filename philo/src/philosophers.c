/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:58:15 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/06 02:47:33 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_philo		philo;
	
	philo = *(t_philo *)args;
	printf("Philosopher %d is thinking\n", philo.philo_id);
	return (NULL);
}

int		philosophers(t_param *param)
{
	int		i;
	param->th = malloc(sizeof(pthread_t) * (param->n_philo + 1));
	param->mutex = malloc(sizeof(pthread_mutex_t) * (param->n_philo + 1));
	param->philos = malloc(sizeof(t_philo) * param->n_philo);
	
	i = 1;
	while (i <= param->n_philo)
	{
		param->philos[i].philo_id = i;
		param->philos[i].t_to_die = param->time_to_die;
		param->philos[i].t_to_eat = param->time_to_eat;
		param->philos[i].t_to_sleep = param->time_to_sleep;
		param->philos[i].ts_must_eat = param->times_must_eat;
		i++;
	}
	
	i = 0;
	while (i < (param->n_philo + 1))
		pthread_mutex_init(&param->mutex[i++], NULL);
	
	i = 1;
    while (i < (param->n_philo + 1))
	{
        if (pthread_create(&param->th[i], NULL, &routine, &param->philos[i]) != 0)
		{
			write(2, "Failed to create thread\n", 25);
			return (-1);
		}
		i++;
    }
	
	i = 1;
    while (i < (param->n_philo + 1))
	{
        if (pthread_join(param->th[i], NULL) != 0) 
		{
            write(2, "Failed to join thread\n", 23);
			return (-1);
        }
		i++;
	}

	i = 0;
	while (i < (param->n_philo + 1))
		pthread_mutex_destroy(&param->mutex[i++]);
	
	free(param->th);
	free(param->mutex);
	free(param->philos);
    return (0);
}