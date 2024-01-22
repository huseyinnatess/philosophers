/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:43:57 by huates            #+#    #+#             */
/*   Updated: 2024/01/22 16:21:53 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_input(char *str[])
{
	int i;
	int j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == ' ')
			{
				j++;
				continue ;
			}
			if (str[i][j] < 48 || str[i][j] > 57)
			{
				write(1, "Error: Invalid input\n", 21);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}