/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:54:12 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/12/02 00:35:03 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_table		table;
	t_philo		*philo;
	int			i;

	if (check_arg(argv, argc) == 1)
	{
		create_table(argc, argv, &table);
		philo = (t_philo *)malloc(sizeof(t_philo) * table.philos_number);
		init_philo(philo, &table);
		create_philo(&table, philo);
		check_die(&table, philo, argv);
		if (table.philos_number == 1)
			pthread_detach(philo[0].thread);
		i = -1;
		while (++i < table.philos_number && table.philos_number != 1)
			pthread_join(philo[i].thread, NULL);
	}
	else
		return (printf("Wrong Argumants\n"), 1);
	if (table.dl != (u_int64_t)-1)
		print(*philo, DIE);
	freephilo(&table, philo);
	return (0);
}
