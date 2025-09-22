/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:13:01 by baecoliv          #+#    #+#             */
/*   Updated: 2025/09/17 17:50:25 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void    set_args(t_args *args, char **av)
{
    args->nb_of_philo       = atoi(av[1]);
    args->time_to_die       = atoi(av[2]);
    args->time_to_eat       = atoi(av[3]);
    args->time_to_sleep     = atoi(av[4]);
    if (av[5])
        args->nb_of_time_to_eat = atoi(av[5]);
    else
        args->nb_of_time_to_eat = 0;
}

void    set_philo(t_mega *mega, int index)
{
    mega->philos[index].args = mega->args; // set les args de chaque philo sur l'adresse de la struct arg dans mega
    mega->philos[index].mega = mega;
    mega->philos->time_now = 0;
    mega->philos[index].start_time = 0;
    mega->philos[index].time_lived = 0;
    mega->philos[index].last_meal = get_time();
    mega->philos[index].is_dead = 0;
    mega->philos[index].nb_to_eat = mega->args->nb_of_time_to_eat;
    if (mega->args->nb_of_philo == 1)
    {
        mega->philos[index].right_fork = &mega->mutex[index];
        mega->philos[index].left_fork = NULL;
    }
    else if (index == mega->args->nb_of_philo - 1)
    {
        mega->philos[index].right_fork = &mega->mutex[index];
        mega->philos[index].left_fork = &mega->mutex[0];
    }
    else
    {
        mega->philos[index].right_fork = &mega->mutex[index];
        mega->philos[index].left_fork = &mega->mutex[index+1];
    }
    // inverser les fork pour les philo pairs (ou impairs)
}

void    set_mega(t_mega *mega)
{
    int i;
    int nbr;

    i = 1;
    nbr = mega->args->nb_of_philo; // c'est pour ca qu'on set mega apres arg, c'est un peu con en vrais mais ¨\_('-')_/¨
    mega->philos = malloc(sizeof(t_philo) * nbr);
    mega->mutex = malloc(sizeof(pthread_mutex_t) * nbr);
    mega->simulation_active = 1;
    mega->simulation_mutex = malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(mega->simulation_mutex, NULL);

    while(i <= nbr)
    {
        pthread_mutex_init(&mega->mutex[i], NULL);
        i++;
    }
    i = 1;
    while(i <= nbr)
    {
        mega->philos[i].index = i;
        set_philo(mega, i);
        i++;
    }
}
