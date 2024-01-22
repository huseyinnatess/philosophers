/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:33:45 by huates            #+#    #+#             */
/*   Updated: 2024/01/22 16:42:30 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdbool.h>

bool is_in_strings(char c, char *str)
{
    while (*str)
    {
        if (*str == c)
            return (true);
        str++;
    }
    return (false);
}

long ft_atoi (char *str)
{
    int sign;
    long result;

    result = 0;
    while (is_in_strings(*str, "\t\n\v\f\r "))
        str++;
    sign = 1;
    while (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign *= -1;
        str++;
    }
    while (*str > '0' && *str < '9')
    {
        result *= 10;
        result += *str - '0';
        str++;
    }
    return (result * sign);
}