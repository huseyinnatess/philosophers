/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:26:49 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/11/02 17:26:57 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int	is_dead(t_table *table)
{
	pthread_mutex_lock(&table->die);
	if (table->is_die != 1)
	{
		pthread_mutex_unlock(&table->die);
		return (1);
	}
	else
		pthread_mutex_unlock(&table->die);
	return (0);
}

void	print(t_philo philo, char *str)
{
	if (is_dead(philo.table) == 1)
	{
		pthread_mutex_lock(&(philo.table->print));
		printf(str, (get_time() - philo.table->start_time), philo.philo_id);
		pthread_mutex_unlock(&(philo.table->print));
	}
	else if (philo.table->dl != 0)
	{
		pthread_mutex_lock(&(philo.table->print));
		printf(str, (philo.table->dl - philo.table->start_time),
			philo.philo_id);
		pthread_mutex_unlock(&(philo.table->print));
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	tmp;

	i = 0;
	sign = 1;
	tmp = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		tmp = (tmp * 10) + (str[i] - 48);
		i++;
	}
	return (tmp * sign);
}

u_int64_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	sensitive_usleep(u_int64_t time)
{
	u_int64_t	wake_up;

	wake_up = get_time() + time;
	while (get_time() < wake_up)
		usleep(100);
}
