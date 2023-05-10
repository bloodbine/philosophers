/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:54:32 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/10 15:40:01 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

int	create_forks(t_data *data)
{
	int	i;

	i = -1;
	data->forks = malloc(data->input.philocount * sizeof(pthread_mutex_t));
	while (++i < data->input.philocount)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
	}
	return (0);
}

int	destroy_forks(t_data *data)
{
	int	i;

	i = -1;
	data->forks = malloc(data->input.philocount * sizeof(pthread_mutex_t));
	while (++i < data->input.philocount)
		pthread_mutex_destroy(&data->forks[i]);
	return (0);
}
