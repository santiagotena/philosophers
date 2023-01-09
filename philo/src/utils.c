/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:09:58 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/09 21:47:46 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_sleep(int ms)
{
	unsigned long long	start_time;

	start_time = get_time_in_ms();
	while(1)
		if((int)(get_time_in_ms() - start_time) >= ms)
			break ;
}

void	philo_sleep(unsigned long long sleep_time, t_param *param)
{
	unsigned long long	wake_up_time;

	wake_up_time = get_time_in_ms() + sleep_time;
	while (get_time_in_ms() < wake_up_time)
	{
		if (param->is_philo_dead)
			break ;
		ft_sleep(1);
	}
}
