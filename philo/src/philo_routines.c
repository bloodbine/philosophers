/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:48:44 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/19 12:58:08 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

void	*routine(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)arg;
	philo = &data->philos[data->threadi];
	while (data->death == 0)
	{
		philo_eat(data, philo);
		philo->meals++;
		if (data->input.rotations != 0 && philo->meals >= data->input.rotations)
			break ;
		philo_sleep(data, philo);
		philo_think(data, philo);
	}
	return (NULL);
}

int	supervisor(t_data *data)
{
	int		i;

	i = 0;
	while (1)
	{
		if (i == data->input.philocount)
			i = 0;
		if (philo_dead(data, &data->philos[i]) == 1)
		{
			data->death = 1;
			data->write = 0;
			detach_philos(data);
			return (1);
		}
		if (data->input.rotations != 0 && data->philos[i].meals == data->input.rotations)
		{
			join_philos(data);
			break ;
		}
	}
	return (0);
}
