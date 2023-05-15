/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:51:39 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/15 15:20:01 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

void	philo_eat(t_data *data, t_philo *philo)
{
	pickup_forks(data, philo);
	pthread_mutex_lock(&data->writelock);
	printf("%lld %d is eating\n", delta_time(data->stime), philo->id);
	pthread_mutex_unlock(&data->writelock);
	usleep(data->input.tt_eat * 1000);
	drop_forks(data, philo);
}

void	philo_sleep(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->writelock);
	printf("%lld %d is sleeping\n", delta_time(data->stime), philo->id);
	pthread_mutex_unlock(&data->writelock);
	usleep(data->input.tt_sleep * 1000);
}

void	philo_think(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->writelock);
	printf("%lld %d is thinking\n", delta_time(data->stime), philo->id);
	pthread_mutex_unlock(&data->writelock);
}
