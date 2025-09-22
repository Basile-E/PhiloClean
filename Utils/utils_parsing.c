/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:04:08 by baecoliv          #+#    #+#             */
/*   Updated: 2025/09/17 17:40:05 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int     ft_isspace(char c)
{
    if (c == ' ' || c == '\t')
        return(1);
    else
        return(0);
}

long	ft_atol(const char *str)
{
	long	nbr;
	int		sign;
	size_t	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (str[i++] - '0') * sign + nbr * 10;
	return (nbr);
}

int check_arg(int ac, char **av)
{
    int     i;

    i = 2; // i est set a 2 parce-que je check av[1] au dessus
    if (ac < 5 || ac > 6)
        return(printf("Error\nUsage : ./philo number_of_philosophers\
 time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"), 1);
    
    if (ft_atol(av[1]) > 200 || ft_atol(av[1]) == 0 || ft_atol(av[1]) < 1)
        return(1);
    while (i < ac)
    {
        if (ft_atol(av[i]) > __INT_MAX__)
            return (1);
        if (ft_atol(av[i]) < 1)
            return (1);
        i++;
    }
    return(0);
}
