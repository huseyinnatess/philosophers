/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:28:46 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/11/03 17:58:35 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <malloc/_malloc.h>

void	freephilo(t_table *table, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < table->philos_number)
		pthread_mutex_destroy(&philo[i].table->forks[i]);
	pthread_mutex_destroy(&table->eating);
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->check);
	pthread_mutex_destroy(&table->die);
	free(philo->table->forks);
	free(philo);
}
