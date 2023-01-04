/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:58:15 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/04 21:35:55 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t mutex; // Delete

void	*routine(void *args)
{
	t_param		param;
	
	param = *(t_param *)args;
	pthread_mutex_lock(&mutex); // Delete
    printf("Hello philosopher #%d\n", param.i);
	pthread_mutex_unlock(&mutex); // Delete
	return (NULL);
}

int		philosophers(t_param *param)
{
	param->th = malloc(sizeof(pthread_t) * (param->n_philo + 1));
	param->mutex = malloc(sizeof(pthread_mutex_t) * (param->n_philo + 1));
	param->i = 0;
	
	pthread_mutex_init(&mutex, NULL); // Delete
    while (param->i < (param->n_philo + 1))
	{
        if (pthread_create(&param->th[param->i], NULL, &routine, param) != 0)
		{
			write(2, "Failed to create thread\n", 25);
			return (-1);
		}
		// printf("%d", param->i);
		param->i++;
    }
	param->i = 0;
    while (param->i < (param->n_philo + 1))
	{
        if (pthread_join(param->th[param->i], NULL) != 0) 
		{
            write(2, "Failed to join thread\n", 23);
			return (-1);
        }
		param->i++;
	}
    return (0);
}