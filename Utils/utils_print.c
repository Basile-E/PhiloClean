/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:08:51 by baecoliv          #+#    #+#             */
/*   Updated: 2025/09/17 16:18:33 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void    print_debug_args(t_args *args)
{
    printf("\nDebug Args\n");
    printf("av[1] Number of Philo       : %i\n", args->nb_of_philo);
    printf("av[2] Time to die           : %ld\n", args->time_to_die);
    printf("av[3] Time to eat           : %ld\n", args->time_to_eat);
    printf("av[4] Time to sleep         : %ld\n", args->time_to_sleep);
    if (args->nb_of_time_to_eat)
        printf("av[5] Number of time to eat : %i\n", args->nb_of_time_to_eat);
}   

void    print_debug_mega(t_mega *mega)
{
    int i;

    print_debug_args(mega->args);
    i = 1;
    while(i <= mega->args->nb_of_philo)
    {
        printf("\nDebug of philo[%i]\n", mega->philos[i].index);
        printf("test arg du philo[%i], number of time to eat : %i\n", mega->philos[i].index, mega->philos[i].nb_to_eat);
        i++;
    }
}
