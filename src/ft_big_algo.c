/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:53:21 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/17 14:45:52 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

bool    number_under_exist(t_data *nb)
{
    int i;
    bool t;

    i = 0;
    t = false;
    while (i < nb->stack_a->count)
    {
        if (nb->stack_a->tab[i] < nb->med)
            t = true;
        i++;
    }
    return (t);
}

bool    number_upper_exist(t_data *nb)
{
    int i;
    bool t;

    i = 0;
    t = false;
    while (i < nb->stack_b->count)
    {
        if (nb->stack_b->tab[i] > nb->med)
            t = true;
        i++;
    }
    return (t);
}

int	ft_big_algo(t_data *nb)
{
    //**************************************
    // printf("\nstack a --------->");
    // for (int i = 0; i < nb->stack_a->count; i++)
	// 	printf("[%d]", nb->stack_a->tab[i]);
	// printf("\nstack b --------->");
    // for (int i = 0; i < nb->stack_b->count; i++)
	// 	printf("[%d]", nb->stack_b->tab[i]);
    //**************************************
    
    while (nb->stack_a->count > 3)
    {
        nb->med = ft_search_median(nb, 0);
        while (number_under_exist(nb) == true && nb->stack_a->count > 3 )
        {  
            if (nb->stack_b->count > 1)
                ft_swap_top(nb);
            if (nb->stack_a->tab[0] >= nb->med)
            {
                if (ft_rotate_both(nb) == true)
                    ft_rr(nb);
                else
                    ft_ra(nb);
            }
            if (nb->stack_a->tab[0] < nb->med)
                ft_pb(nb);
            if (nb->stack_b->count == 3)
                ft_solve_3b(nb);
        }
    }
    if (nb->stack_a->count == 3)
        ft_solve_3a(nb);
    //printf ("\nsecond sorting\n");
    int nbr;
    while (nb->stack_b->count > 0)
    {
        if (ft_best_option(nb, ft_search_max(nb, 1), ft_search_max2(nb, 1)) == 1)
        {
            nbr = ft_search_max(nb, 1);
            while (nb->stack_b->tab[0] != nbr)
            {
                if (ft_best_move(nb, nbr) == 1)
                {
                    if (ft_rotate_both(nb) == true)
                        ft_rr(nb);
                    else
                        ft_rb(nb);
                }
                else if (ft_best_move(nb, nbr) == 0)
                {
                    if (ft_reverse_rotate_both(nb) == true)
                        ft_rrr(nb);
                    else
                        ft_rrb(nb);
                }
                //**************************************
                // printf("\nstack a --------->");
                // for (int i = 0; i < nb->stack_a->count; i++)
                //     printf("[%d]", nb->stack_a->tab[i]);
                // printf("\nstack b --------->");
                // for (int i = 0; i < nb->stack_b->count; i++)
                //     printf("[%d]", nb->stack_b->tab[i]);
                //**************************************   
            }
        }
        //sleep(1);
        if (ft_best_option(nb, ft_search_max(nb, 1), ft_search_max2(nb, 1)) == 0)
        {
            nbr = ft_search_max2(nb, 1);
            while (nb->stack_b->tab[0] != nbr)
            {
                if (ft_best_move(nb, nbr) == 1)
                {
                    if (ft_rotate_both(nb) == true)
                        ft_rr(nb);
                    else
                        ft_rb(nb);
                }
                else if (ft_best_move(nb, nbr) == 0)
                {
                    if (ft_reverse_rotate_both(nb) == true)
                        ft_rrr(nb);
                    else
                        ft_rrb(nb);
                }
                //sleep(1);
                //**************************************
                // printf("\nstack a --------->");
                // for (int i = 0; i < nb->stack_a->count; i++)
                //     printf("[%d]", nb->stack_a->tab[i]);
                // printf("\nstack b --------->");
                // for (int i = 0; i < nb->stack_b->count; i++)
                //     printf("[%d]", nb->stack_b->tab[i]);
                //**************************************   
            }
        }
        if (nb->stack_b->tab[0] == ft_search_max(nb, 1) || nb->stack_b->tab[0] == ft_search_max2(nb, 1))
        {
            //sleep(1);
            //**************************************
            // printf("\nstack a --------->");
            // for (int i = 0; i < nb->stack_a->count; i++)
            //     printf("[%d]", nb->stack_a->tab[i]);
            // printf("\nstack b --------->");
            // for (int i = 0; i < nb->stack_b->count; i++)
            //     printf("[%d]", nb->stack_b->tab[i]);
            //**************************************
            ft_pa(nb);
            ft_swap_top(nb);
        }
        //sleep(1);
    }    






    
    // int i;
    // int x;
    // int back;
    // x = 3;

    // while (nb->stack_b->count > 0)
    // {
    //     i = 0;
    //     back = 0;
    //     //nb->med = ft_mid_value(nb, x);
    //     nb->med = ft_search_median(nb, 1);
    //     while (i < x && nb->stack_b->count > 3)
    //     {
    //         if ((nb->stack_b->tab[0] <= nb->med) && (nb->stack_b->tab[1] > nb->med))
    //         {
    //             ft_sb(nb);
    //             ft_pa(nb);
    //         }
    //         else if ((nb->stack_b->tab[0] <= nb->med) && (nb->stack_b->tab[1] < nb->med))
    //         {
    //             ft_rb(nb);
    //             back++;
    //         }
    //         else if (nb->stack_b->tab[0] > nb->med)
    //             ft_pa(nb);
    //         i++;
    //     }
    //     i = 0;
    //     while (i < back && nb->stack_b->count > 3)
    //     {
    //         ft_rrb(nb);
    //         ft_pa(nb);
    //         i++;
    //     }
    //     if (nb->stack_b->count == 3)
    //     {
    //         ft_solve_3b(nb);
    //         while (nb->stack_b->count > 0)
    //             ft_pa(nb);
    //     }
    //     x *= 2;
    // }
    return (nb->moves);
}
