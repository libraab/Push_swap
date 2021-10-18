/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_algo2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 08:44:30 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/18 19:08:57 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_big_algo2(t_data *nb)
{
    int max;
    int nbr;
    int i;
    

    i = 0;
    max = ft_search_max(nb, 0);
    while (nb->stack_a->count > 2) //pushhing everything to be
    {
        if (nb->stack_a->tab[0] == max)
            ft_ra(nb);
        else
            ft_pb(nb);
    }
    
    while (nb->stack_a->count > 1 && nb->stack_b->count > 0) //pushing back to a
    {
        nbr = ft_best_mv(nb);
        while ((nb->stack_b->tab[0] != nbr) || nb->stack_a->tab[0] != ft_search_next_b(nb, nbr))
        {
            if ((ft_real_index_b(nb, nbr) <= nb->stack_b->count / 2) && (ft_real_index_a(nb, ft_search_next_b(nb, nbr)) <= nb->stack_a->count / 2))
                ft_top_top(nb, nbr);
            if ((ft_real_index_b(nb, nbr) > nb->stack_b->count / 2) && (ft_real_index_a(nb, ft_search_next_b(nb, nbr)) > nb->stack_a->count / 2))
                ft_bot_bot(nb, nbr);
            if ((ft_real_index_b(nb, nbr) <= nb->stack_b->count / 2) && (ft_real_index_a(nb, ft_search_next_b(nb, nbr)) > nb->stack_a->count / 2))
                ft_top_bot(nb, nbr);
            if ((ft_real_index_b(nb, nbr) > nb->stack_b->count / 2) && (ft_real_index_a(nb, ft_search_next_b(nb, nbr)) <= nb->stack_a->count / 2))
                ft_bot_top(nb, nbr);
        }
        if (nb->stack_b->tab[0] == nbr && nb->stack_a->tab[0] == ft_search_next_b(nb, nbr))
            ft_pa(nb);
    }
    while (nb->stack_a->tab[0] != ft_search_min(nb, 0))
    {
        if (ft_real_index_a(nb, ft_search_min(nb, 0)) > nb->stack_a->count / 2)
            ft_rra(nb);
        else
            ft_ra(nb);
    }
    return(1);
}