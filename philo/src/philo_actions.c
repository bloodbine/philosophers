/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:51:39 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/22 13:25:56 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

void	print(t_data *data, long long time, int id, char *status)
{
	pthread_mutex_lock(&data->locks.l_print);
	if (data->write == 1)
		printf("%lld %d %s\n", time, id, status);
	pthread_mutex_unlock(&data->locks.l_print);
}

void	philo_eat(t_data *data, t_philo *philo)
{
	pickup_forks(data, philo);
	print(data, delta_time(data->stime), philo->id, "is eating");
	pthread_mutex_lock(&philo->l_eat);
	philo->eating = 1;
	pthread_mutex_unlock(&philo->l_eat);
	pthread_mutex_lock(&philo->l_time);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->l_time);
	ft_usleep(philo->last_meal, data->input.tt_eat);
	drop_forks(data, philo);
	philo->meals += 1;
	pthread_mutex_lock(&philo->l_eat);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->l_eat);
}

void	philo_sleep(t_data *data, t_philo *philo)
{
	print(data, delta_time(data->stime), philo->id, "is sleeping");
	ft_usleep(philo->last_meal + philo->data->input.tt_eat, data->input.tt_sleep);
}

void	philo_think(t_data *data, t_philo *philo)
{
	print(data, delta_time(data->stime), philo->id, "is thinking");
}

int	philo_dead(t_data *data, t_philo *philo)
{
	if (philo->done == 1)
		return (0);
	pthread_mutex_lock(&philo->l_time);
	if (delta_time(philo->last_meal) > data->input.tt_die)
	{
		pthread_mutex_lock(&philo->l_eat);
		if (philo->eating == 0)
		{
			pthread_mutex_unlock(&philo->l_eat);
			pthread_mutex_unlock(&philo->l_time);
			print(data, delta_time(data->stime), philo->id, "died");
			pthread_mutex_lock(&data->locks.l_death);
			data->death = 1;
			pthread_mutex_unlock(&data->locks.l_death);
			pthread_mutex_lock(&data->locks.l_write);
			data->write = 0;
			pthread_mutex_unlock(&data->locks.l_write);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->l_eat);
	pthread_mutex_unlock(&philo->l_time);
	return (0);
}
