/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:53:21 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/11 18:30:18 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void ft_search_median(t_data *nb, int x)
{
    if (x == 0)
        nb->med = nb->stack_a->tab[nb->stack_a->count / 2];
    if (x == 1)
        nb->med = nb->stack_b->tab[nb->stack_b->count / 2];
}

int	ft_solve_more2(t_data *nb)
{
    int i;
    
    while (nb->stack_a->count > 3 && (ft_stack_sorted(nb, nb->stack_a->count, 0) == 0))
    {
        i = 0;
        ft_search_median(nb, 0);
        while ((nb->stack_a->tab[0] != nb->med) && (ft_stack_sorted(nb, nb->stack_a->count, 0) == 0) && (nb->stack_a->count > 3))
        {   
            if ((nb->stack_a->tab[0] > nb->med) && (nb->stack_b->tab[0] > nb->stack_b->tab[nb->stack_b->count - 1]))
                ft_rr(nb);
            if (nb->stack_a->tab[0] > nb->med)
                ft_ra(nb);
            if (nb->stack_a->tab[0] < nb->med)
                ft_pb(nb);
            if (nb->stack_b->count == 3)
                ft_solve_3b(nb);
        }
    }
    if (nb->stack_a->count == 3)
        ft_solve_3a(nb);
    ft_search_median(nb, 1);
    while ((nb->stack_b->count > 0) && (ft_stack_sorted(nb, nb->stack_b->count, 1) == 0))
    {
        if (nb->stack_b->tab[0] > nb->med)
        {
            if (nb->stack_a->tab[0] > nb->stack_a->tab[nb->stack_a->count - 1])
                ft_rr(nb);
            else
                ft_rb(nb);
        }
        else
        {
            ft_pa(nb);
            if (nb->stack_a->tab[0] > nb->stack_a->tab[nb->stack_a->count - 1])
                ft_ra(nb);
            if (nb->stack_a->tab[0] > nb->stack_a->tab[1])
                ft_sa(nb);
        }
                
        if (nb->stack_b->count == 3)
            ft_solve_3b(nb);
    }
    if ((ft_stack_sorted(nb, nb->stack_b->count, 1) == 1) && (ft_stack_sorted(nb, nb->stack_a->count, 0) == 1))
    {
        while (nb->stack_b->count > 0)
            ft_pa(nb);
    }
    return (1);
}

// int	ft_solve_more2(t_data *nb)
// {
//     int i;

//     while (!ft_all_sorted(nb))
//     {
//         i = 0;
//         while (nb->stack_a->tab[0] != ft_search_min(nb, 0) && (ft_stack_sorted(nb, nb->stack_a->count, 0) == 0)) //&& nb->stack_a->tab[0] != ft_search_min2(nb, 0)) && (ft_stack_sorted(nb, nb->stack_a->count, 0) == 0))
//         {
//             if (nb->stack_a->tab[i] == ft_search_min(nb, 0))
//             {
//                 if (i <= (nb->stack_a->count / 2))
//                 {
//                     while (nb->stack_a->tab[0] != ft_search_min(nb, 0))
//                         ft_ra(nb);
//                 }
//                 else
//                 {
//                     while (nb->stack_a->tab[0] != ft_search_min(nb, 0))
//                         ft_rra(nb);
//                 }
//             }
//             if (nb->stack_a->tab[i] == ft_search_min2(nb, 0))
//             {
//                 if (i <= (nb->stack_a->count / 2))
//                 {
//                     while (nb->stack_a->tab[0] != ft_search_min2(nb, 0))
//                         ft_ra(nb);
//                 }
//                 else
//                 {
//                     while (nb->stack_a->tab[0] != ft_search_min2(nb, 0))
//                         ft_rra(nb);
//                 }
//             }
//             i++;
//         }
//         while ((nb->stack_a->count > 3) && (ft_stack_sorted(nb, nb->stack_a->count, 0) == 0))
//         {
//             if (nb->stack_a->tab[0] == ft_search_min(nb, 0))
//             {
//                 ft_pb(nb);
//                 ft_solve_more2(nb);
//             }
//         }
//         if (nb->stack_a->count == 3)
//             ft_solve_3(nb);
//         while (nb->stack_b->count > 0)
//         {
//             ft_pa(nb);
//             if (nb->stack_a->tab[0] > nb->stack_a->tab[1])
//             {
//                 if (nb->stack_a->tab[0] > nb->stack_a->tab[nb->stack_a->count - 1])
//                     ft_ra(nb);
//                 else
//                     ft_sa(nb);
//             }
//         }
//     }
    
//     return (1);
// }
    