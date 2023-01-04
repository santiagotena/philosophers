/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 23:25:12 by stena-he          #+#    #+#             */
/*   Updated: 2023/01/04 01:59:18 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_param		*param;

	if (argc < 5 || argc > 6)
	{
		write(2, "Invalid number of arguments\n", 29);
		return (-1);
	}
	param = malloc(sizeof(t_param));
	if (parse_args(argc, argv, param) < 0)
	{
		free(param);
		return (-1);
	}
	free(param);
	return (0);
}
