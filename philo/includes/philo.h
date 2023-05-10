/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:46:25 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/10 10:32:54 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h> // time calculation
# include <pthread.h> // threads
# include <stdbool.h> // bools
# include <unistd.h> // usleep
# include <stdlib.h> // exit code definitions
# include <stdio.h> // printf

typedef struct s_forks
{
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}				t_forks;

typedef struct s_philo
{
	struct s_forks	forks;
}				t_philo;

typedef struct s_data
{
	pthread_t		*philosophers;
	pthread_mutex_t	*forks;
	long long		tt_die;
	long long		tt_eat;
	long long		tt_sleep;
	long long		time_start;
	bool			death;
}				t_data;

int64_t	atoint64(char	*num);

#endif