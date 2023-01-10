/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 01:54:01 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/10 23:49:03 by stena-he         ###   ########.fr       */
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

int	ft_atoi_mod(const char *str)
{
	long int	output;
	long int	sign;
	int			i;

	output = 0;
	sign = 1;
	i = 0;
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
	{
		write(2, "BIG BOY\n", 9);
		return (-1);
	}
	return ((int)(output));
}

int	parse_args_check(t_param *param)
{
	if (param->n_philo < 0)
		return (-1);
	if ((int)param->time_to_die < 0)
		return (-1);
	if (param->time_to_eat < 0)
		return (-1);
	if (param->time_to_sleep < 0)
		return (-1);
	if (param->times_must_eat < 0)
		return (-1);
	return (0);
}

int	parse_args(int argc, char **argv, t_param *param)
{
	param->is_philo_dead = 0;
	param->n_philo = ft_atoi_mod(argv[1]);
	if (param->n_philo == 0)
	{
		write(2, "Invalid argument\n", 18);
		return (-1);
	}
	param->time_to_die = ft_atoi_mod(argv[2]);
	param->time_to_eat = ft_atoi_mod(argv[3]);
	param->time_to_sleep = ft_atoi_mod(argv[4]);
	if (argc == 6)
	{
		param->times_must_eat = ft_atoi_mod(argv[5]);
		param->is_times_must_eat = 1;
	}
	else
		param->times_must_eat = 0;
	if (parse_args_check(param) < 0)
		return (-1);
	return (0);
}
