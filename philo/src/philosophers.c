/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:58:15 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/04 19:47:46 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_param		param;
	
	param = *(t_param *)args;
    printf("Hiello");
	return (NULL);
}

int		philosophers(t_param *param)
{
	pthread_t	th[param->number_of_philosophers];

	param->i = 0;
    while (param->i < param->number_of_philosophers)
	{
        if (pthread_create(&th[param->i], NULL, &routine, param) != 0)
		{
			write(2, "Failed to create thread\n", 25);
			return (-1);
		}
		param->i++;
    }
	param->i = 0;
    while (param->i < param->number_of_philosophers)
	{
        if (pthread_join(th[param->i], NULL) != 0) 
		{
            write(2, "Failed to join thread\n", 23);
			return (-1);
        }
		param->i++;
    }
    return (0);
}