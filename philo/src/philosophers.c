/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:58:15 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/09 01:38:00 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	mut; // Delete

void	*routine(void *args)
{
	t_philo		philo;
	
	philo = *(t_philo *)args;
	pthread_mutex_lock(&mut); // Delete
	take_fork(&philo);
	eat(&philo);
	sleeping(&philo);
	think(&philo);
	die(&philo);
	pthread_mutex_unlock(&mut); // Delete
	
	return (NULL);
}

int		philosophers(t_param *param)
{
	int		i;
	
	param->th = malloc(sizeof(pthread_t) * (param->n_philo + 1));
	param->mutex = malloc(sizeof(pthread_mutex_t) * (param->n_philo + 1));
	param->philos = malloc(sizeof(t_philo) * param->n_philo);

	pthread_mutex_init(&mut, NULL); // Delete
	
	i = 1;
	while (i <= param->n_philo)
	{
		param->philos[i].philo_id = i;
		param->philos[i].ts_must_eat = param->times_must_eat;
		i++;
	}
	
	i = 0;
	while (i < (param->n_philo + 1))
		pthread_mutex_init(&param->mutex[i++], NULL);
	
	i = 1;
	// param->start_time = malloc(sizeof(time_t));
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
	
	pthread_mutex_destroy(&mut); // Delete
	
	free(param->th);
	free(param->mutex);
	free(param->philos);
	// free(param->start_time);
    return (0);
}