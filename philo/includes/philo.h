/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:46:25 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/10 15:59:44 by gpasztor         ###   ########.fr       */
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

//	Pointers to the fork mutexes
typedef struct s_forks
{
	int	l_fork;
	int	r_fork;
}				t_forks;

//	Required data for each Philosopher
typedef struct s_philo
{
	struct s_forks	forks;
	bool			alive;
	int				mealcount;
	int				id;
}				t_philo;

//	Collection of all ARGV input data
typedef struct s_input
{
	int				philocount;
	long long		tt_die;
	long long		tt_eat;
	long long		tt_sleep;
	int				rotations;
}				t_input;

//	Primary data storage
typedef struct s_data
{
	pthread_mutex_t	*forks;
	t_philo			*philos;
	t_input			input;
	long long		stime;
	bool			death;
}				t_data;

int			read_inputs(int argc, char **argv, t_data *data);
int			my_atoi(char *num);
long long	my_atoll(char *num);
long long	get_time(void);
int			create_philos(t_data *data);
void		fill_philo(t_data *data, int left, int right);
long long	delta_time(long long time);
int			create_forks(t_data *data);
int			destroy_forks(t_data *data);

#endif