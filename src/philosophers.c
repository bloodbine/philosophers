/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:43:45 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/08 17:46:14 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philosophers.h"

int	main(int argc, char **argv)
{
	struct timeval	time;
	t_data			data;

	gettimeofday(&time, NULL);
	data.time_start = time.tv_usec * 1000;
	if (argc == 4 || argc == 5)
	{
		data.tt_die = atouint64(argv[1]);
		data.tt_eat = atouint64(argv[2]);
		data.tt_sleep = atouint64(argv[3]);
		printf("Time to die: %llu\n", data.tt_die);
		printf("Time to eat: %llu\n", data.tt_eat);
		printf("Time to sleep: %llu\n", data.tt_sleep);
		gettimeofday(&time, NULL);
		printf("Run time: %llu\n", (time.tv_usec * 1000) - data.time_start);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
