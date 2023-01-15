/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:42:02 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/15 04:43:42 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(int ms)
{
	unsigned long long	start_time;

	start_time = get_time_in_ms();
	while (1)
		if ((int)(get_time_in_ms() - start_time) >= ms)
			break ;
}

void	philo_sleep(unsigned long long sleep_time, t_param *param)
{
	unsigned long long	wake_up_time;

	wake_up_time = get_time_in_ms() + sleep_time;
	while (get_time_in_ms() < wake_up_time)
	{
		if (are_all_alive(param))
			ft_sleep(1);
		else
			break ;
	}
}
