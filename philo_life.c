/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:27:24 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/11/02 17:27:25 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	routine(t_philo *philo)
{
	pthread_mutex_lock(&(philo->table->forks[philo->l_fork]));
	print(*philo, RIGHT_FORK);
	pthread_mutex_lock(&(philo->table->forks[philo->r_fork]));
	print(*philo, LEFT_FORK);
	pthread_mutex_lock(&philo->table->eating);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->table->eating);
	print(*philo, EAT);
	philo->number_meals++;
	sensitive_usleep(philo->table->eat_time);
	pthread_mutex_unlock(&(philo->table->forks[philo->l_fork]));
	pthread_mutex_unlock(&(philo->table->forks[philo->r_fork]));
	print(*philo, SLEEP);
	sensitive_usleep(philo->table->sleep_time);
	print(*philo, THINK);
}

void	*philolife(void *tmp)
{
	t_philo	*philo;

	philo = (t_philo *)tmp;
	if (philo->philo_id % 2 != 0)
		sensitive_usleep(10);
	pthread_mutex_lock(&philo->table->die);
	while (philo->table->is_die == 0)
	{
		pthread_mutex_unlock(&philo->table->die);
		routine(philo);
		if (philo->table->sum_eat != -1
			&& philo->number_meals >= philo->table->sum_eat)
		{
			pthread_mutex_lock(&philo->table->check);
			philo->table->eat = 1;
			pthread_mutex_unlock(&philo->table->check);
			break ;
		}
		pthread_mutex_lock(&philo->table->die);
	}
	pthread_mutex_unlock(&philo->table->die);
	return (NULL);
}
