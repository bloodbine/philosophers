/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:43:45 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/19 13:06:27 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data			data;

	if (argc == 5 || argc == 6)
	{
		if (read_inputs(argc, argv, &data) == -1)
			return (system("leaks philo"));
		if (create_forks(&data) != 0)
			return (system("leaks philo"));
		data.death = 0;
		data.stime = get_time();
		if (create_philos(&data) != 0)
			return (system("leaks philo"));
		data.threadi = -1;
		while (++(data.threadi) < data.input.philocount)
		{
			pthread_create(&(data.philos[data.threadi].pthread), NULL,
				&routine, &data);
		}
		supervisor(&data);
		destroy_forks(&data);
		return (system("leaks philo"));
	}
	return (system("leaks philo"));
}
 