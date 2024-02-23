/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:51:47 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/11/02 12:51:51 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define EAT \
"\033[0;34m[%d] \033[0;33mphilo(%d)\033[0;32mphilo is eating\033[0m\n"
# define SLEEP \
"\033[0;34m[%d] \033[0;33mphilo(%d)\033[0;35mphilo sleeping\033[0m\n"
# define THINK \
"\033[0;34m[%d] \033[0;33mphilo(%d)\033[0;37mphilo thinking\033[0m\n"
# define DIE \
"\033[0;34m[%d] \033[0;33mphilo(%d)\033[0;31mphilo died :(\033[0m\n"
# define RIGHT_FORK \
"\033[0;34m[%d] \033[0;33mphilo(%d)\033[0;36mphilo took the right fork\033[0m\n"
# define LEFT_FORK \
"\033[0;34m[%d] \033[0;33mphilo(%d)\033[0;36mphilo took the left fork\033[0m\n"

# include <pthread.h>

typedef struct s_philo
{
	struct s_table	*table;
	int				philo_id;
	int				number_meals;
	u_int64_t		last_eat;
	int				r_fork;
	int				l_fork;
	pthread_t		thread;
}	t_philo;

typedef struct s_table
{
	t_philo			*philos;
	int				is_die;
	int				eat;
	int				philos_number;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	u_int64_t		die_time;
	u_int64_t		start_time;
	u_int64_t		dl;
	int				sum_eat;
	pthread_mutex_t	eating;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	die;
	pthread_mutex_t	check;

}	t_table;

void		create_table(int argc, char **argv, t_table *table);
void		init_philo(t_philo *philo, t_table *table);
int			create_philo(t_table *table, t_philo *philo);
void		print(t_philo philo, char *str);
int			ft_atoi(const char *str);
u_int64_t	get_time(void);
int			check_arg(char **argv, int argc);
void		sensitive_usleep(u_int64_t time);
void		philolifes(t_philo *philo);
void		*philolife(void *tmp);
void		freephilo(t_table *table, t_philo *philo);
void		check_die(t_table *table, t_philo *philo, char **argv);
int			is_dead(t_table *table);
#endif
