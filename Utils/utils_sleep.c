/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:19:51 by baecoliv          #+#    #+#             */
/*   Updated: 2025/09/17 16:18:45 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int my_sleep(long time, t_philo *philo)
{
    long now = get_time();
    //lock
    while (philo->mega->simulation_active && is_dead(philo) == 0)
    {
        //printf("get time = %ld\n, now = %ld\n, time = %ld\n", get_time(), now, time);
        if ((get_time() - now) >= time)
            break;
        usleep(100); 
    }
    //unlock
    return (1);


//     int i;
 
//     i = 0;
//     while(i <= time)
//     {
//         usleep(100);
//         i += 100;
//         /*
//             ici il faut que je check si le philo est dead
//             je devrais probablement faire une meilleur fonction is_dead
//         */
//         // if (is_dead(philo) == 1)
//         //     break;
//     }

//     return (1);
}

void    go_sleep(t_philo *philo)
{
    long time;
    long ptime;
    
    time = get_time();
    ptime = time - philo->start_time;
    
    printf("%ld %i is sleeping\n", ptime, philo->index);
    my_sleep(philo->args->time_to_sleep, philo);
}
