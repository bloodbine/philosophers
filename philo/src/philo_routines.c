/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:48:44 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/20 15:49:43 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->data->ready != 1)
	{
		if (philo->id == philo->data->input.philocount)
		{
			philo->data->stime = get_time();
			philo->data->ready = 1;
		}
	}
	if (philo->id % 2 == 0)
		usleep(philo->data->input.tt_eat - 10);
	while (philo->data->death == 0)
	{
		philo_eat(philo->data, philo);
		if (++(philo->meals) == philo->data->input.rotations)
		{
			philo->done = 1;
			break ;
		}
		philo_sleep(philo->data, philo);
		philo_think(philo->data, philo);
	}
	return (NULL);
}

int	supervisor(t_data *data)
{
	int		i;

	i = 0;
	while (1)
	{
		if (data->philos[i].done == 1)
			i += 1;
		if (i >= data->input.philocount)
			i = 0;
		if (philo_dead(data, &data->philos[i]) == 1)
		{
			data->death = 1;
			data->write = 0;
			detach_philos(data);
			return (1);
		}
	}
	return (0);
}
