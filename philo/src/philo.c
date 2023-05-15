/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:43:45 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/15 17:03:52 by gpasztor         ###   ########.fr       */
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
		data.stime = get_time();
		if (create_philos(&data) != 0)
			return (EXIT_FAILURE);
		data.threadi = -1;
		while (++(data.threadi) < data.input.philocount)
		{
			pthread_create(&(data.philos[data.threadi].pthread), NULL,
				&routine, &data);
			usleep(50);
		}
		join_philos(&data);
		destroy_forks(&data);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
