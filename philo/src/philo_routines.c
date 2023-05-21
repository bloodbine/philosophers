/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:48:44 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/21 13:57:15 by gpasztor         ###   ########.fr       */
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
	philo->last_meal = get_time();
	if (philo->id % 2 != 0)
		ft_usleep(philo->data->input.tt_eat);
	pthread_mutex_lock(&philo->data->statelock);
	while (philo->data->death == 0)
	{
		pthread_mutex_unlock(&philo->data->statelock);
		philo_eat(philo->data, philo);
		if (++(philo->meals) == philo->data->input.rotations)
		{
			philo->done = 1;
			return (NULL);
		}
		philo_sleep(philo->data, philo);
		philo_think(philo->data, philo);
		pthread_mutex_lock(&philo->data->statelock);
	}
	pthread_mutex_unlock(&philo->data->statelock);
	return (NULL);
}

int	count_done(t_data	*data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->input.philocount)
	{
		if (data->philos[i].done == 1)
			j += 1;
		i += 1;
	}
	return (j);
}

int	supervisor(t_data *data)
{
	int		i;

	i = 0;
	while (data->ready == 0)
		i = 0;
	while (1)
	{
		if (data->philos[i].done == 1)
			i += 1;
		if (i >= data->input.philocount)
			i = 0;
		if (philo_dead(data, &data->philos[i]) == 1)
		{
			detach_philos(data);
			return (1);
		}
		if (count_done(data) == data->input.philocount)
		{
			print(data, delta_time(data->stime), data->philos[i].id, "done");
			detach_philos(data);
			return (0);
		}
	}
	return (0);
}
