/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:03:52 by baecoliv          #+#    #+#             */
/*   Updated: 2025/09/17 16:52:03 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>



/*Struct*/
typedef struct s_mega t_mega;

typedef struct  s_args
{
    int         nb_of_philo;
    long        time_to_die;
    long        time_to_eat;
    long        time_to_sleep;
    int         nb_of_time_to_eat;
}               t_args;

typedef struct  s_philo
{
    struct timeval tv;
    pthread_t   tid;
    int         index;
    long        time_now;
    long        start_time;
    long        time_lived;
    long        last_meal;
    t_args      *args;
    t_mega      *mega;
    pthread_mutex_t     *left_fork;
    pthread_mutex_t     *right_fork;
}               t_philo;

typedef struct  s_mega
{
    t_args      *args;
    t_philo     *philos;
    pthread_mutex_t     *mutex;
    int         simulation_active;
    pthread_mutex_t     *simulation_mutex;
}               t_mega;
/*Fin Struct*/

/*Prototypes*/
void    print_debug_args(t_args *args);
void    print_debug_mega(t_mega *mega);
long    get_time();
void    set_args(t_args *args, char **av);
void    set_philo(t_mega *mega, int index);
void    set_mega(t_mega *mega);
void    think(t_philo *philo);
void    eat(t_philo *philo);
void    die(t_philo *philo);
int     try_to_eat(t_philo *philo);
int     is_dead(t_philo *philo);
int     my_sleep(long time, t_philo *philo);
void    go_sleep(t_philo *philo);
void    *be_philo(void *data);
int     check_arg(int ac, char **av);

/*Fin Prototypes*/