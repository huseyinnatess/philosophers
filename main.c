/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:49:49 by huates            #+#    #+#             */
/*   Updated: 2024/01/22 16:38:57 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char *argv[])
{
    t_data data;
    
    if (argc < 5 || argc > 6)
        return (1);
    if (check_input(argv))
        return (1);
    if (init(&data, argv, argc))
        return (1);
}
