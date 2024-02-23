/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:34:00 by ercdeniz          #+#    #+#             */
/*   Updated: 2024/02/23 14:39:26 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <malloc/_malloc.h>

void	create_table(int argc, char **argv, t_table *table)
{
	int	i;

	i = -1;
	table->philos_number = ft_atoi(argv[1]);
	table->die_time = ft_atoi(argv[2]);
	table->eat_time = ft_atoi(argv[3]);
	table->sleep_time = ft_atoi(argv[4]);
	table->start_time = get_time();
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philos_number);
	table->dl = -1;
	table->sum_eat = -1;
	table->is_die = 0;
	table->eat = 0;
	if (argc == 6)
		table->sum_eat = ft_atoi(argv[5]);
	while (++i < table->philos_number)
		pthread_mutex_init(&table->forks[i], NULL);
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->eating, NULL);
	pthread_mutex_init(&table->die, NULL);
	pthread_mutex_init(&table->check, NULL);
}

static void	fork_init(t_table *table, t_philo *philo, int i)
{
	if (i == 0)
	{
		philo->l_fork = i;
		philo->r_fork = table->philos_number - 1;
	}
	else
	{
		philo->l_fork = i;
		philo->r_fork = i - 1;
	}
}

void	init_philo(t_philo *philo, t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philos_number)
	{
		philo[i].philo_id = i + 1;
		philo[i].table = table;
		philo[i].number_meals = 0;
		fork_init(table, &philo[i], i);
		philo[i].last_eat = table->start_time;
	}
}

int	create_philo(t_table *table, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < table->philos_number)
		pthread_create(&philo[i].thread, NULL, &philolife, &philo[i]);
	return (0);
}
