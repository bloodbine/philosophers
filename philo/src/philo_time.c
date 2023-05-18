/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:01:32 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/18 15:02:45 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

long long	delta_time(long long time)
{
	return (get_time() - time);
}

void	ft_usleep(long long time_to_sleep)
{
	long long	start;

	start = get_time();
	while (1)
	{
		if (get_time() == (start + time_to_sleep))
			return ;
	}
}
