/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:53:21 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/08 16:43:16 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_solve_more2(t_data *nb)
{
    int i;

    while (!ft_all_sorted(nb))
    {
        i = 0;
        while ((nb->stack_a->tab[0] != ft_search_min(nb, 0) && nb->stack_a->tab[0] != ft_search_min2(nb, 0)) && (ft_stack_sorted(nb, nb->stack_a->count, 0) == 0))
        {
            if (nb->stack_a->tab[i] == ft_search_min(nb, 0))
            {
                if (i <= (nb->stack_a->count / 2))
                {
                    while (nb->stack_a->tab[0] != ft_search_min(nb, 0))
                        ft_ra(nb);
                }
                else
                {
                    while (nb->stack_a->tab[0] != ft_search_min(nb, 0))
                        ft_rra(nb);
                }
            }
            if (nb->stack_a->tab[i] == ft_search_min2(nb, 0))
            {
                if (i <= (nb->stack_a->count / 2))
                {
                    while (nb->stack_a->tab[0] != ft_search_min2(nb, 0))
                        ft_ra(nb);
                }
                else
                {
                    while (nb->stack_a->tab[0] != ft_search_min2(nb, 0))
                        ft_rra(nb);
                }
            }
            i++;
        }
        while ((nb->stack_a->count > 3) && (ft_stack_sorted(nb, nb->stack_a->count, 0) == 0))
        {
            if (nb->stack_a->tab[0] == ft_search_min(nb, 0) || nb->stack_a->tab[0] == ft_search_min2(nb, 0))
            {
                ft_pb(nb);
                ft_solve_more2(nb);
            }
        }
        if (nb->stack_a->count == 3)
            ft_solve_3(nb);
        while (nb->stack_b->count > 0)
        {
            ft_pa(nb);
            if (nb->stack_a->tab[0] > nb->stack_a->tab[1])
            {
                if (nb->stack_a->tab[0] > nb->stack_a->tab[nb->stack_a->count - 1])
                    ft_ra(nb);
                else
                    ft_sa(nb);
            }
        }
    }
    
    return (1);
}
    