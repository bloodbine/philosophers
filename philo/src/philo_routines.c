/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:48:44 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/22 13:26:56 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

void	wait_for_others(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->data->locks.l_ready);
		if (philo->id == philo->data->input.philocount)
		{
			philo->data->ready = 1;
			philo->data->stime = get_time();
		}
		if (philo->data->ready == 1)
			break ;
		pthread_mutex_unlock(&philo->data->locks.l_ready);
	}
	pthread_mutex_unlock(&philo->data->locks.l_ready);
	pthread_mutex_lock(&philo->l_time);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->l_time);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_for_others(philo);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->stime, philo->data->input.tt_eat);
	while (1)
	{
		pthread_mutex_lock(&philo->data->locks.l_death);
		if (philo->data->death == 1)
			break ;
		pthread_mutex_unlock(&philo->data->locks.l_death);
		philo_eat(philo->data, philo);
		if (philo->meals == philo->data->input.rotations)
		{
			pthread_mutex_lock(&philo->data->locks.l_done);
			philo->done = 1;
			pthread_mutex_unlock(&philo->data->locks.l_done);
			break ;
		}
		philo_sleep(philo->data, philo);
		philo_think(philo->data, philo);
	}
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
	while (1)
	{
		pthread_mutex_lock(&data->locks.l_ready);
		if (data->ready == 1)
			break ;
		pthread_mutex_unlock(&data->locks.l_ready);
	}
	pthread_mutex_unlock(&data->locks.l_ready);
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
