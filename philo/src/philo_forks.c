/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:54:32 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/21 13:52:29 by gpasztor         ###   ########.fr       */
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
	if (pthread_mutex_init(&data->writelock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->statelock, NULL) != 0)
		return (1);
	return (0);
}

void	pickup_forks(t_data *data, t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(&data->forks[philo->forks.l_fork]);
		print(data, delta_time(data->stime), philo->id, "has taken a fork");
		pthread_mutex_lock(&data->forks[philo->forks.r_fork]);
		print(data, delta_time(data->stime), philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&data->forks[philo->forks.r_fork]);
		print(data, delta_time(data->stime), philo->id, "has taken a fork");
		pthread_mutex_lock(&data->forks[philo->forks.l_fork]);
		print(data, delta_time(data->stime), philo->id, "has taken a fork");
	}
}

void	drop_forks(t_data *data, t_philo *philo)
{
	pthread_mutex_unlock(&data->forks[philo->forks.l_fork]);
	print(data, delta_time(data->stime), philo->id, "dropped a fork");
	pthread_mutex_unlock(&data->forks[philo->forks.r_fork]);
	print(data, delta_time(data->stime), philo->id, "dropped a fork");
}

int	destroy_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->input.philocount)
	{
		if (pthread_mutex_destroy(&data->forks[i]) != 0)
			return (1);
	}
	pthread_mutex_destroy(&data->writelock);
	free(data->forks);
	return (0);
}
