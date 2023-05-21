/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:51:39 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/21 13:57:30 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

void	print(t_data *data, long long time, int id, char *status)
{
	pthread_mutex_lock(&data->writelock);
	if (data->write == 1)
		printf("%lld %d %s\n", time, id, status);
	pthread_mutex_unlock(&data->writelock);
}

void	philo_eat(t_data *data, t_philo *philo)
{
	pickup_forks(data, philo);
	print(data, delta_time(data->stime), philo->id, "is eating");
	philo->eating = 1;
	philo->last_meal = get_time();
	ft_usleep(data->input.tt_eat);
	drop_forks(data, philo);
	philo->eating = 0;
}

void	philo_sleep(t_data *data, t_philo *philo)
{
	print(data, delta_time(data->stime), philo->id, "is sleeping");
	ft_usleep(data->input.tt_sleep);
}

void	philo_think(t_data *data, t_philo *philo)
{
	print(data, delta_time(data->stime), philo->id, "is thinking");
}

int	philo_dead(t_data *data, t_philo *philo)
{
	if (philo->done == 1)
		return (0);
	if (delta_time(philo->last_meal) > data->input.tt_die && philo->eating == 0)
	{
		print(data, delta_time(data->stime), philo->id, "died");
		pthread_mutex_lock(&data->statelock);
		data->death = 1;
		data->write = 0;
		pthread_mutex_unlock(&data->statelock);
		return (1);
	}
	return (0);
}
