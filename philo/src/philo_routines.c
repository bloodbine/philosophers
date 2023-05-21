/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:48:44 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/21 14:41:26 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	
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
	while (data->ready == 0)
		i = 0;
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
