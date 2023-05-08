/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:46:25 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/08 17:38:52 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h> // time calculation
# include <pthread.h> // threads
# include <unistd.h> // usleep
# include <stdlib.h> // exit code definitions
# include <stdio.h> // printf

typedef struct s_data
{
	pthread_t		*philosophers;
	pthread_mutex_t	*forks;
	uint64_t		tt_die;
	uint64_t		tt_eat;
	uint64_t		tt_sleep;
	uint64_t		time_start;
}				t_data;

uint64_t	atouint64(char	*num);

#endif