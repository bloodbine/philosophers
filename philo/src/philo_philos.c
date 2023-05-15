/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:54:37 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/15 12:16:19 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

int	create_philos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	data->philos = malloc(data->input.philocount * sizeof(t_philo) - 1);
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
	data->philos[left].id = right;
	data->philos[left].alive = 0;
	if (right == 1)
		data->philos[left].forks.l_fork = data->input.philocount - 1;
	else
		data->philos[left].forks.l_fork = left - 1;
	data->philos[left].forks.r_fork = right - 1;
	data->philos[left].meals = 0;
	data->philos[left].last_meal = data->stime;
	// printf("Data for philo: %d\n", data->philos[left].id);
	// printf("Alive: %d\n", data->philos[left].alive);
	// printf("Left fork: %d\n", data->philos[left].forks.l_fork);
	// printf("Right fork: %d\n", data->philos[left].forks.r_fork);
	// printf("Mealcount: %d\n", data->philos[left].mealcount);
	// printf("Last meal: %lld\n\n", data->philos[left].last_meal);
}
