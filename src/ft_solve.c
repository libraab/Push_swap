/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:18:39 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/28 16:41:50 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void    ft_init_stack(t_stack *x, t_data *nb)
{
    x->val_max = nb->tab[0];
	x->val_min = nb->tab[0];
	x->val_med = nb->tab[nb->tot / 2];
    x->tab = malloc(sizeof(int) * 3);
}

void    ft_solve_2(void)
{
        printf("sa\n");
		exit(EXIT_SUCCESS);
}

void    ft_solve_3(t_data *nb)
{
    if (nb->tab[0] == nb->stack_a->val_max)
    {
        if (nb->tab[2] == nb->stack_a->val_min)
        {
            printf("ra\nsa\n");
            exit(EXIT_SUCCESS);
	    }
        else
        {
            printf("ra\n");
            exit(EXIT_SUCCESS);
        }   
    }
    if (nb->tab[0] == nb->stack_a->val_min)
    {
            printf("sa\nra\n");
            exit(EXIT_SUCCESS);
    }
    else
    {
        if (nb->tab[2] == nb->stack_a->val_min)
        {
            printf("rra\n");
            exit(EXIT_SUCCESS);
	    }
        else
            ft_solve_2();
    }
}

//void    ft_solve_4(t_data *nb)
// {

// }


void    ft_solve_all(t_data *nb)
{
    int i;

    i = 0;
    nb->stack_a = malloc(sizeof(t_stack));
    ft_init_stack(nb->stack_a, nb);
     //nb->stack_b = malloc(sizeof(t_stack)); //not necessary for now
    // printf("taille du tableau %lu\n", (sizeof(int) * 10));
    // printf("taille du pointeur de nb->tab %lu\n", sizeof(int *));
    // printf("taille de la structure %lu\n", sizeof(t_data));
    //ft_init_stack(nb->stack_b, nb); //uncomment if used
    while (i < nb->tot)
    {
        if (nb->tab[i] > nb->stack_a->val_max)
            nb->stack_a->val_max = nb->tab[i];
        if (nb->tab[i] < nb->stack_a->val_min)
            nb->stack_a->val_min = nb->tab[i];
        i++;
    }
    if (nb->tot == 2)
        ft_solve_2();
    if (nb->tot == 3)
        ft_solve_3(nb);
    // if (nb->tot == 4)
    //     ft_solve_4(nb);
}

