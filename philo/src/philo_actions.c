/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:51:39 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/21 16:04:55 by gpasztor         ###   ########.fr       */
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
	philo->eating = 1;
	pthread_mutex_lock(&philo->l_time);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->l_time);
	ft_usleep(data->input.tt_eat);
	drop_forks(data, philo);
	philo->meals += 1;
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
		pthread_mutex_lock(&data->locks.l_death);
		data->death = 1;
		pthread_mutex_unlock(&data->locks.l_death);
		pthread_mutex_lock(&data->locks.l_write);
		data->write = 0;
		pthread_mutex_unlock(&data->locks.l_write);
		return (1);
	}
	return (0);
}
