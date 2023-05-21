/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:54:37 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/21 16:03:42 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

int	create_philos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	data->philos = malloc(data->input.philocount * sizeof(t_philo));
	if (data->philos == NULL)
		return (1);
	while (i < data->input.philocount)
	{
		fill_philo(data, i, j);
		i++;
		j++;
	}
	return (0);
}

void	fill_philo(t_data *data, int left, int right)
{
	data->philos[left].data = data;
	data->philos[left].id = right;
	if (right == 1)
		data->philos[left].forks.l_fork = data->input.philocount - 1;
	else
		data->philos[left].forks.l_fork = left - 1;
	data->philos[left].forks.r_fork = right - 1;
	data->philos[left].meals = 0;
	data->philos[left].done = 0;
	data->philos[left].eating = 0;
}

void	start_philos(t_data *data)
{
	while ((data->threadi) < data->input.philocount)
	{
		pthread_mutex_lock(&data->locks.l_thread);
		pthread_create(&(data->philos[data->threadi].pthread), NULL,
			&routine, &data->philos[data->threadi]);
		data->threadi += 1;
	}
}

int	join_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->input.philocount)
	{
		if (pthread_join(data->philos[i].pthread, NULL) != 0)
			return (1);
	}
	return (0);
}

int	detach_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->input.philocount)
	{
		if (pthread_detach(data->philos[i].pthread) != 0)
			return (1);
	}
	return (0);
}
