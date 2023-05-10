/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:43:45 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/10 16:02:30 by gpasztor         ###   ########.fr       */
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
		create_philos(&data);
		destroy_forks(&data);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

// printf("%d %lld %lld %lld %d\n", data.input.philocount, data.input.tt_die, data.input.tt_eat, data.input.tt_sleep, data.input.rotations);