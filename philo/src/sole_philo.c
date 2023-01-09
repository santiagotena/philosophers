/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sole_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:45:32 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/09 22:01:23 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sole_philo(int time_to_die)
{
	unsigned long long		start_time;
	unsigned long long		current_time;

	start_time = get_time_in_ms();
	current_time = get_time_in_ms() - start_time;
	printf("%llu ms: 1 has taken a fork\n", current_time);
	ft_sleep(time_to_die);
	current_time = get_time_in_ms() - start_time;
	printf("%llu ms: 1 has died\n", current_time);
}
