/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:20:43 by baecoliv          #+#    #+#             */
/*   Updated: 2025/09/17 16:19:13 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void    *be_philo(void *data)
{
    t_philo *philo;
    //long    now;
    
    philo = (t_philo *)data; 
    philo->start_time = get_time();
    //philo->time_now = get_time();
    // printf("\nje pense a l'index %i\ndonc je suis %ld\n", philo->index, philo->tid);
    while(philo->mega->simulation_active)
    {
        if (philo->mega->simulation_active) // c'est pas propre mais ca empeche les philo d'aller pioncer apres leurs mort
            think(philo);
        if (philo->mega->simulation_active)
            try_to_eat(philo);
        if (philo->mega->simulation_active)
            go_sleep(philo);
        // now = get_time();
        // philo->time_lived = now - philo->start_time;
    }
    return NULL;
    //int i;
    
    // i = 0;
    // while (i < philo->args->nb_of_philo)
    // {
    //     pthread_join(philo->tid, NULL);
    //     i++;
    // }
}
