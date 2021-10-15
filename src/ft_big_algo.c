/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:53:21 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/15 20:09:36 by abouhlel         ###   ########.fr       */
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
    
    int i;
    int x;
    int back;
    x = 3;

    while (nb->stack_b->count > 0)
    {
        i = 0;
        back = 0;
        nb->med = ft_mid_value(nb, x);
        while (i < x && nb->stack_b->count > 3)
        {
            if (nb->stack_b->tab[0] <= nb->med)
            {
                if (nb->stack_b->tab[1] > nb->med)
                {
                    if (ft_2a_not_sorted(nb) == true)
                        ft_ss(nb);
                    else
                        ft_sb(nb);
                    ft_pa(nb);
                }
                else
                {
                    if (ft_rotate_both(nb) == true)
                        ft_rr(nb);
                    else if (ft_rotate_both(nb) == false)
                        ft_rb(nb);
                    back++;
                }
            }
            if (nb->stack_b->tab[0] > nb->med)
            {
                ft_pa(nb);
                ft_swap_top(nb);
            }
            i++;
        }
        i = 0;
        while (i < back && nb->stack_b->count > 3)
        {
            if (ft_reverse_rotate_both(nb) == true)
                ft_rrr(nb);
            else
                ft_rrb(nb);
            
            ft_pa(nb);
            i++;
        }
        if (nb->stack_b->count == 3)
        {
            ft_solve_3b(nb);
            while (nb->stack_b->count > 0)
                ft_pa(nb);
        }
        x *= 2;
    }
    return (nb->moves);
}
