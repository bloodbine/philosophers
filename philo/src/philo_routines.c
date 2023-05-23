/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:48:44 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/23 15:57:33 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

int	check_hunger(t_philo *philo)
{
	if (philo->meals == philo->data->input.rotations)
	{
		pthread_mutex_lock(&philo->data->locks.l_done);
		philo->done = 1;
		pthread_mutex_unlock(&philo->data->locks.l_done);
		return (1);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->locks.l_ready);
	pthread_mutex_unlock(&philo->data->locks.l_ready);
	pthread_mutex_lock(&philo->l_time);
	philo->last_meal = philo->data->stime;
	pthread_mutex_unlock(&philo->l_time);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->stime, philo->data->input.tt_eat);
	pthread_mutex_lock(&philo->data->locks.l_death);
	while (philo->data->death != 1)
	{
		pthread_mutex_unlock(&philo->data->locks.l_death);
		philo_eat(philo->data, philo);
		if (check_hunger(philo) == 1)
			break ;
		philo_sleep(philo->data, philo);
		philo_think(philo->data, philo);
		pthread_mutex_lock(&philo->data->locks.l_death);
	}
	pthread_mutex_unlock(&philo->data->locks.l_death);
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

void	supervisor(t_data *data)
{
	int		i;

	i = 0;
	ft_usleep(get_time(), data->input.philocount * 2);
	data->stime = get_time();
	pthread_mutex_unlock(&data->locks.l_ready);
	ft_usleep(get_time(), 1);
	while (1)
	{
		if (data->philos[i].done == 1)
			i += 1;
		if (i >= data->input.philocount)
			i = 0;
		if (philo_dead(data, &data->philos[i]) == 1)
			break ;
		if (count_done(data) == data->input.philocount)
		{
			join_philos(data);
			break ;
		}
	}
}
