/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:46:25 by gpasztor          #+#    #+#             */
/*   Updated: 2023/05/20 12:03:53 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h> // time calculation
# include <pthread.h> // threads
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
	pthread_t		pthread;
	struct s_forks	forks;
	long long		last_meal;
	int				eating;
	int				meals;
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
	pthread_mutex_t	writelock;
	pthread_t		supervisor;
	t_philo			*philos;
	t_input			input;
	long long		stime;
	int				threadi;
	int				death;
	int				write;
}				t_data;

// Philosopher actions

int			supervisor(t_data *data);
void		*routine(void *arg);
void		philo_eat(t_data *data, t_philo *philo);
void		philo_sleep(t_data *data, t_philo *philo);
void		philo_think(t_data *data, t_philo *philo);
void		philo_print(t_data *data, long long time, int id, char *status);
int			philo_dead(t_data *data, t_philo *philo);

// Time Utils

long long	get_time(void);
long long	delta_time(long long time);
void		ft_usleep(long long time_to_sleep);

// Input Utils

int			read_inputs(int argc, char **argv, t_data *data);
int			my_atoi(char *num);
long long	my_atoll(char *num);

// Fork Utils
int			create_forks(t_data *data);
int			pickup_forks(t_data *data, t_philo *philo);
int			drop_forks(t_data *data, t_philo *philo);
int			destroy_forks(t_data *data);

// Philo Utils

int			create_philos(t_data *data);
void		fill_philo(t_data *data, int left, int right);
void		start_philos(t_data *data);
int			join_philos(t_data *data);
int			detach_philos(t_data *data);

#endif