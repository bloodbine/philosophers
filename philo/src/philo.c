/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:43:45 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/21 14:13:09 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data			data;

	if (argc == 5 || argc == 6)
	{
		if (read_inputs(argc, argv, &data) == -1)
			return (EXIT_FAILURE);
		if (create_forks(&data) != 0)
			return (EXIT_FAILURE);
		data.death = 0;
		if (create_philos(&data) != 0)
			return (EXIT_FAILURE);
		data.ready = 0;
		data.threadi = -1;
		start_philos(&data);
		if (supervisor(&data) == 1)
			return (EXIT_SUCCESS);
		destroy_forks(&data);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
 