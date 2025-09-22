/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:21:35 by baecoliv          #+#    #+#             */
/*   Updated: 2025/09/17 16:54:46 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int main(int ac, char **av)
{
    t_mega *mega;
    int    i;

    /*vérrif*/
    if (check_arg(ac, av))
        return(1);
    mega = malloc(sizeof(t_mega));
    if (!mega)
        return(printf("failed to malloc mega"), 1);
    mega->args = malloc(sizeof(t_args));
    if (!mega->args)
        return(printf("failled to malloc args"), 1);
    /*vérrif*/

    set_args(mega->args, av);
    set_mega(mega);
    //set_philo(mega->philos, mega->args);
    //print_debug_mega(mega);

    /*set toutes les donnés, sera une fonction set_all qui prend mega et av en params*/

    i = 1;
    while(i <= mega->args->nb_of_philo)
    {
        pthread_create(&mega->philos[i].tid, NULL, be_philo, &mega->philos[i]);
        i++;
    }

    /*
        ici la fonction KILL_ALL
        elle devrait check si il y un des philos qui est dead
        pourra etre une fonction qui prend mega comme arg et qui loop jusqua trouver une condition d'arret puis renverra 1
        (trop manger ou dead) (au final elle est dans utils philo et c'est is dead)
    */
    i = 1;
    while(42)
    {
        if (mega->simulation_active == 0)
        {
            i = 1;
            while (i <= mega->args->nb_of_philo)
            {
                pthread_join(mega->philos[i].tid, NULL);
                i++;
            }
            return(0);
        }    
    }


    /*End Sim loop*/
    // i = 1;
    // while (i <= mega->args->nb_of_philo)
    // {
    //     pthread_join(mega->philos[i].tid, NULL);
    //     i++;
    // }
    //usleep(1000); //sert a attendre la fin du programme pour remplacer les joins (le premier thread fini trop vite donc le programme se ferme)
    return(0);
}
