/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:51:39 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/18 14:55:42 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

void	philo_eat(t_data *data, t_philo *philo)
{
	pickup_forks(data, philo);
	pthread_mutex_lock(&data->writelock);
	printf("%lld %d is eating\n", delta_time(data->stime), philo->id);
	pthread_mutex_unlock(&data->writelock);
	philo->eating = 1;
	ft_usleep(data->input.tt_eat);
	philo->last_meal = get_time();
	drop_forks(data, philo);
	philo->eating = 0;
}

void	philo_sleep(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->writelock);
	printf("%lld %d is sleeping\n", delta_time(data->stime), philo->id);
	pthread_mutex_unlock(&data->writelock);
	ft_usleep(data->input.tt_sleep);
}

void	philo_think(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->writelock);
	printf("%lld %d is thinking\n", delta_time(data->stime), philo->id);
	pthread_mutex_unlock(&data->writelock);
}

int	philo_dead(t_data *data, t_philo *philo)
{
	if (delta_time(philo->last_meal) >= data->input.tt_die && philo->eating == 0)
	{
		pthread_mutex_lock(&data->writelock);
		printf("DEBUG: %lld %lld Philo %d\n", delta_time(philo->last_meal), data->input.tt_die, philo->id);
		pthread_mutex_unlock(&data->writelock);
		return (1);
	}
	return (0);
}
