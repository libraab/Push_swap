/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:18:39 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/29 14:32:42 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void    ft_init_val(t_data *nb)
{
    int i;

    i = 0;
    nb->val_max = nb->initial_tab[0];
	nb->val_min = nb->initial_tab[0];
    nb->med = nb->tot / 2;
    while (i < nb->tot)
    {
        if (nb->initial_tab[i] > nb->val_max)
            nb->val_max = nb->initial_tab[i];
        if (nb->initial_tab[i] < nb->val_min)
            nb->val_min = nb->initial_tab[i];
        i++;
    }
}

void    ft_transfert(t_data *nb)
{
    int i;

    i = 0;
    //=================================================
    nb->stack_a->tab = malloc (sizeof (int) * nb->tot);
    //=================================================
    while (i < nb->tot)
    {
        nb->stack_a->tab[i] = nb->initial_tab[i];
        i++;
    }
}

void    ft_solve_2(t_data *nb)
{
    ft_sa(nb);
    exit(EXIT_SUCCESS);
}

void    ft_solve_3(t_data *nb)
{
    if (nb->initial_tab[0] == nb->val_max)
    {
        if (nb->initial_tab[2] == nb->val_min)
        {
            printf("ra\nsa\n");
            exit(EXIT_SUCCESS);
	    }
        else
        {
            ft_ra(nb, nb->tot);
            exit(EXIT_SUCCESS);
        }   
    }
    if (nb->initial_tab[0] == nb->val_min)
    {
        printf("sa\nra\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        if (nb->initial_tab[2] == nb->val_min)
        {
            printf("rra\n");
            exit(EXIT_SUCCESS);
	    }
        else
            ft_solve_2(nb);
    }
}

// void    ft_solve_more(t_data *nb)
// {
    
// }


void    ft_solve_all(t_data *nb)
{
    int i;

    i = 0;
    //====================================
    nb->stack_a = malloc(sizeof(t_stack));
    //====================================
    ft_init_val(nb);
    ft_transfert(nb);
    
    if (nb->tot == 2)
        ft_solve_2(nb);
    if (nb->tot == 3)
        ft_solve_3(nb);
        
    // if (nb->tot > 3)
    //     ft_solve_more(nb);
    //****************************************************
     //nb->stack_b = malloc(sizeof(t_stack)); //not necessary for now
    // printf("taille du tableau %lu\n", (sizeof(int) * 10));
    // printf("taille du pointeur de nb->tab %lu\n", sizeof(int *));
    // printf("taille de la structure %lu\n", sizeof(t_data));
    //ft_init_stack(nb->stack_b, nb); //uncomment if used
    //****************************************************
}

