/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:28:07 by ercdeniz          #+#    #+#             */
/*   Updated: 2024/02/23 14:42:08 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		while (argv[++i])
		{
			j = -1;
			while (argv[i][++j])
			{
				if (!(argv[i][j] >= '0' && argv[i][j] <= '9')
					|| argv[i][0] == '0')
					return (0);
			}
		}
	}
	else
		return (0);
	return (1);
}

void	check_die(t_table *table, t_philo *philo, char **argv)
{
	int	i;

	pthread_mutex_lock(&table->check);
	while (table->eat == 0)
	{
		pthread_mutex_unlock(&table->check);
		i = -1;
		while (++i < ft_atoi(argv[1]) && is_dead(table) == 1)
		{
			pthread_mutex_lock(&philo->table->eating);
			if (get_time() - philo[i].last_eat >= table->die_time
				&& philo[i].number_meals != table->sum_eat)
			{
				table->dl = get_time();
				pthread_mutex_lock(&table->die);
				table->is_die = 1;
				pthread_mutex_unlock(&table->die);
			}
			pthread_mutex_unlock(&philo->table->eating);
		}
		if (is_dead(table) == 0)
			break ;
		pthread_mutex_lock(&table->check);
	}
	pthread_mutex_unlock(&table->check);
}
