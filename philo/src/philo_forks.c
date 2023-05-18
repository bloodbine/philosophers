/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:54:32 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/18 15:47:13 by gpasztor         ###   ########.fr       */
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
	return (0);
}

int	pickup_forks(t_data *data, t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (pthread_mutex_lock(&data->forks[philo->forks.l_fork]) != 0)
			return (1);
		if (data->write == 1)
			printf("%lld %d has taken a fork\n", delta_time(data->stime), philo->id);
		if (pthread_mutex_lock(&data->forks[philo->forks.r_fork]) != 0)
			return (1);
		if (data->write == 1)
			printf("%lld %d has taken a fork\n", delta_time(data->stime), philo->id);
	}
	else
	{
		if (pthread_mutex_lock(&data->forks[philo->forks.r_fork]) != 0)
			return (1);
		if (data->write == 1)
			printf("%lld %d has taken a fork\n", delta_time(data->stime), philo->id);
		if (pthread_mutex_lock(&data->forks[philo->forks.l_fork]) != 0)
			return (1);
		if (data->write == 1)
			printf("%lld %d has taken a fork\n", delta_time(data->stime), philo->id);
	}
	return (0);
}

int	drop_forks(t_data *data, t_philo *philo)
{
	if (pthread_mutex_unlock(&data->forks[philo->forks.l_fork]) != 0)
		return (1);
	if (pthread_mutex_unlock(&data->forks[philo->forks.r_fork]) != 0)
		return (1);
	return (0);
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
