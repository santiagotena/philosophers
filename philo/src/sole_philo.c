/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sole_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:42:03 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/07 12:26:59 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sole_philo(int time_to_die)
{
	time_t		start_time;

	start_time = get_time_in_ms();
	usleep(time_to_die * 1000);
	printf("%ld ms: 1 has died\n", (get_time_in_ms() - start_time));
}
