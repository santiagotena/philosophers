/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 01:54:01 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/04 02:02:02 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	exit_atoi(long int output, int i)
{
	if (output < -2147483648 || output > 2147483647)
		return (-1);
	if ((i > 10 && output < -2147483648) || (i > 9 && output > 2147483647))
		return (-1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/**
 * @brief Converts the initial portion of the string pointed to by str to 
 * int representation.
 * 
 * @param str 
 * @return int 
 */
int	ft_atoi_mod(const char *str)
{
	long int	output;
	long int	sign;
	int			i;

	output = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			write(2, "Invalid argument\n", 18);
			return (-1);
		}
		output = output * 10 + (str[i] - '0');
		i++;
	}
	output = sign * output;
	if (exit_atoi(output, i) < 0)
		return (-1);
	return ((int)(output));
}

int	parse_args(int argc, char **argv, t_param *param)
{
	param->number_of_philosophers = ft_atoi_mod(argv[1]);
	param->time_to_die = ft_atoi_mod(argv[2]);
	param->time_to_eat = ft_atoi_mod(argv[3]);
	param->time_to_sleep = ft_atoi_mod(argv[4]);
	if (argc == 6)
		param->number_of_times_must_eat = ft_atoi_mod(argv[5]);
	if (param->number_of_philosophers < 0)
		return (-1);
	if (param->time_to_die < 0)
		return (-1);
	if (param->time_to_eat < 0)
		return (-1);
	if (param->time_to_sleep < 0)
		return (-1);
	if (param->number_of_times_must_eat < 0)
		return (-1);
	return (0);
}