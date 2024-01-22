/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:26:27 by huates            #+#    #+#             */
/*   Updated: 2024/01/22 16:40:38 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>
# include <stdint.h>

int	init_data(t_data *data, char *argv[], int argc)
{
	data->philo_num = (int) ft_atoi(argv[1]);
	data->death_time = (u_int64_t)ft_atoi(argv[2]);
	data->eat_time = (u_int64_t)ft_atoi(argv[3]);
	data->sleep_time = (u_int64_t)ft_atoi(argv[4]);
	if (argc == 6)
		data->meals_nb = (int) ft_atoi(argv[5]);
	else
		data->meals_nb = -1;
	if (data->philo_num < 2 || data->philo_num > 200 || data->death_time < 0
		|| data->eat_time < 0 || data->sleep_time < 0)
	{
		write(1, "Error: Invalid input\n", 21);
		return (1);
	}
    data -> dead = 0;
    data -> finished = 0;
    pthread_mutex_init(&data->lock, NULL);
    pthread_mutex_init(&data->write, NULL);
    return (0);
}

int	init(t_data *data, char *argv[], int argc)
{
	if (init_data(data, argv, argc))
		return (1);
    return (0);
}