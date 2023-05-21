/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:43:45 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/21 15:50:43 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

int	setup_data(int argc, char **argv, t_data *data)
{
	if (read_inputs(argc, argv, data) == 1)
		return (1);
	if (create_forks(data) == 1)
		return (1);
	if (create_keychain(data) == 1)
		return (1);
	if (create_philos(data) == 1)
		return (1);
	data->write = 1;
	data->death = 0;
	data->ready = 0;
	data->threadi = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;

	if (argc == 5 || argc == 6)
	{
		if (setup_data(argc, argv, &data) == 1)
			return (EXIT_FAILURE);
		printf("Setup ready\n");
		printf("Required rotations: %d\n", data.input.rotations);
		start_philos(&data);
		printf("Philos started\n");
		if (supervisor(&data) == 1)
			return (EXIT_SUCCESS);
		printf("Program done\n");
		destroy_keychain(&data);
		destroy_forks(&data);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
