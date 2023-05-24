/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:43:45 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/24 15:19:49 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

int	setup_data(int argc, char **argv, t_data *data)
{
	if (read_inputs(argc, argv, data) == 1)
		return (1);
	if (data->input.rotations == 0)
		return (2);
	if (create_forks(data) == 1)
		return (1);
	if (create_keychain(data) == 1 && destroy_forks(data) == 0)
		return (1);
	if (create_philos(data) == 1)
	{
		destroy_forks(data);
		destroy_keychain(data);
		return (1);
	}
	if (data->input.tt_die < data->input.tt_eat)
		data->input.tt_eat = data->input.tt_die + 10;
	if (data->input.tt_die < data->input.tt_sleep)
		data->input.tt_sleep = data->input.tt_die + 10;
	data->write = 1;
	data->death = 0;
	data->ready = 0;
	data->threadi = 0;
	return (0);
}

void	*murder(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	data->stime = get_time();
	pthread_mutex_lock(&data->forks[0]);
	print(data, delta_time(data->stime), 1, "has taken a fork");
	ft_usleep(get_time(), data->input.tt_die);
	print(data, delta_time(data->stime), 1, "has died");
	pthread_mutex_unlock(&data->forks[0]);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data			data;

	if (argc == 5 || argc == 6)
	{
		if (setup_data(argc, argv, &data) == 1)
			return (EXIT_FAILURE);
		if (data.input.rotations == 0)
			return (EXIT_SUCCESS);
		if (data.input.philocount == 1)
		{
			pthread_create(&data.philos[0].pthread, NULL,
				&murder, &data);
			pthread_join(data.philos[0].pthread, NULL);
		}
		else
			start_philos(&data);
		destroy_keychain(&data);
		destroy_forks(&data);
		free(data.philos);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
