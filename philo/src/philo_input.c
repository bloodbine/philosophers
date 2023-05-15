/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:05:53 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/10 16:32:17 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

long long	my_atoll(char *num)
{
	long long	converted;
	int			i;

	i = -1;
	while (num[++i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (-1);
	}
	i = -1;
	converted = 0;
	while (num[++i])
	{
		converted += (num[i] - '0');
		if (num[i + 1] != '\0')
			converted *= 10;
	}
	return (converted);
}

int	my_atoi(char *num)
{
	int	converted;
	int	i;

	i = -1;
	while (num[++i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (-1);
	}
	i = -1;
	converted = 0;
	while (num[++i])
	{
		converted += (num[i] - '0');
		if (num[i + 1] != '\0')
			converted *= 10;
	}
	return (converted);
}

int	read_inputs(int argc, char **argv, t_data *data)
{
	data->input.philocount = my_atoi(argv[1]);
	if (data->input.philocount <= 0)
		return (-1);
	data->input.tt_die = my_atoll(argv[2]);
	if (data->input.tt_die == -1)
		return (-1);
	data->input.tt_eat = my_atoll(argv[3]);
	if (data->input.tt_eat == -1)
		return (-1);
	data->input.tt_sleep = my_atoll(argv[4]);
	if (data->input.tt_sleep == -1)
		return (-1);
	if (argc == 6)
	{
		data->input.rotations = my_atoi(argv[5]);
		if (data->input.rotations == -1)
			return (-1);
	}
	else
		data->input.rotations = 0;
	return (0);
}
