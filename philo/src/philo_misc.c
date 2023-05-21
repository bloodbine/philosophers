/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:44:43 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/21 14:50:39 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

int	create_keychain(t_data *data)
{
	if (pthread_mutex_init(data->locks.l_thread, NULL) == 1)
		return (1);
	if (pthread_mutex_init(data->locks.l_ready, NULL) == 1)
		return (1);
	if (pthread_mutex_init(data->locks.l_write, NULL) == 1)
		return (1);
	if (pthread_mutex_init(data->locks.l_death, NULL) == 1)
		return (1);
	if (pthread_mutex_init(data->locks.l_done, NULL) == 1)
		return (1);
}

int	destroy_keychain(t_data *data)
{
	if (pthread_mutex_destroy(data->locks.l_thread) == 1)
		return (1);
	if (pthread_mutex_destroy(data->locks.l_ready) == 1)
		return (1);
	if (pthread_mutex_destroy(data->locks.l_write) == 1)
		return (1);
	if (pthread_mutex_destroy(data->locks.l_death) == 1)
		return (1);
	if (pthread_mutex_destroy(data->locks.l_done) == 1)
		return (1);
}