/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:48:44 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/15 16:57:17 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

void	*routine(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)arg;
	philo = &data->philos[data->threadi];
	pthread_join(philo->pthread, NULL);
	while (philo->alive == 0 && data->death == 0)
	{
		if (data->input.rotations != 0 && philo->meals >= data->input.rotations)
			break ;
		philo_eat(data, philo);
		philo_sleep(data, philo);
		philo_think(data, philo);
	}
	return (NULL);
}
