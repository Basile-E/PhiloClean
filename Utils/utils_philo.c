/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:14:57 by baecoliv          #+#    #+#             */
/*   Updated: 2025/09/17 17:47:08 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h" 

void    think(t_philo *philo)
{
    long time;

    time = get_time();
    long ptime;
    ptime = time - philo->start_time;

    printf("%ld %i is thinking\n",ptime, philo->index);
}

void    eat(t_philo *philo)
{
    long time;

    time = get_time();
    long ptime;
    ptime = time - philo->start_time;

    printf("%ld %i is eating\n", ptime, philo->index);
    my_sleep(philo->args->time_to_eat, philo);
    philo->last_meal = get_time();
}

void    die(t_philo *philo)
{
    long time;

    time = get_time();
    long ptime;
    ptime = time - philo->start_time;

    printf("%ld %i died\n", ptime, philo->index);
    pthread_mutex_lock(philo->mega->simulation_mutex);
    philo->mega->simulation_active = 0;
    pthread_mutex_unlock(philo->mega->simulation_mutex);
}

int     try_to_eat(t_philo *philo)
{
    long time;

    time = get_time();
    long ptime;
    ptime = time - philo->start_time;
    
    pthread_mutex_lock(philo->right_fork);
    printf("%ld %i has taken a fork\n", ptime, philo->index);
    pthread_mutex_lock(philo->left_fork);
    printf("%ld %i has taken a fork\n", ptime, philo->index);
    eat(philo);
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
    return(1);
}

int     is_dead(t_philo *philo)
{
    long time;

    time = get_time();
    if (time - philo->last_meal > philo->args->time_to_die)
    {
        die(philo);
        return(1);
    }
    else
        return(0);
}