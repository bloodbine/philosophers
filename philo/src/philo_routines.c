/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:48:44 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/17 11:53:43 by gpasztor         ###   ########.fr       */
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
		philo_eat(data, philo);
		philo->meals++;
		philo_sleep(data, philo);
		philo_think(data, philo);
		if (data->input.rotations != 0 && philo->meals >= data->input.rotations)
			break ;
	}
	return (NULL);
}
