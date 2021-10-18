/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:53:21 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/18 14:12:50 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_big_algo(t_data *nb)
{
    int nbr;
    
    while (nb->stack_a->count > 3) // pushing a
    {
        nb->med = ft_search_median(nb, 0);
        while (number_under_exist(nb) == true && nb->stack_a->count > 3 )
        {  
            if (nb->stack_b->count > 1)
                ft_swap_top(nb);
            if (nb->stack_a->tab[0] >= nb->med)
            {
                // if (ft_rotate_both(nb) == true)
                //     ft_rr(nb);
                // else
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
    
    while (nb->stack_b->count > 0) // pushing back to a
    {
        if (ft_best_option(nb, ft_search_max(nb, 1), ft_search_max2(nb, 1)) == 1)
        {
            nbr = ft_search_max(nb, 1);
            while (nb->stack_b->tab[0] != nbr)
            {
                if (ft_best_move(nb, nbr) == 1)
                {
                    // if (ft_rotate_both(nb) == true)
                    //     ft_rr(nb);
                    // else
                        ft_rb(nb);
                }
                else if (ft_best_move(nb, nbr) == 0)
                {
                    if (ft_reverse_rotate_both(nb) == true)
                        ft_rrr(nb);
                    else
                        ft_rrb(nb);
                }
            }
        }
        if (ft_best_option(nb, ft_search_max(nb, 1), ft_search_max2(nb, 1)) == 0)
        {
            nbr = ft_search_max2(nb, 1);
            while (nb->stack_b->tab[0] != nbr)
            {
                if (ft_best_move(nb, nbr) == 1)
                {
                    // if (ft_rotate_both(nb) == true)
                    //     ft_rr(nb);
                    // else
                        ft_rb(nb);
                }
                else if (ft_best_move(nb, nbr) == 0)
                {
                    if (ft_reverse_rotate_both(nb) == true)
                        ft_rrr(nb);
                    else
                        ft_rrb(nb);
                }
            }
        }
        if (nb->stack_b->tab[0] == ft_search_max(nb, 1) || nb->stack_b->tab[0] == ft_search_max2(nb, 1))
        {
            ft_pa(nb);
            ft_swap_top(nb);
        }
        if (nb->stack_b->count == 3)
        {
            ft_solve_3b(nb);
            while (nb->stack_b->count > 0 && ft_stack_sorted(nb, nb->stack_a->count, 1) == 1)
            {
                ft_pa(nb);
                ft_swap_top(nb);
            }
        }
        
    }    
    return (nb->moves);
}
