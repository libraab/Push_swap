/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:23:58 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/18 18:51:28 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int ft_index_a(t_data *nb, int nbr)//return the mv_count
{
    int i;

    i = 0;
    while (i < nb->stack_a->count)
    {
        if (nb->stack_a->tab[i] == nbr)
        {
            if (i <= nb->stack_a->count / 2)
                return(i);
            else
                return (nb->stack_a->count - i);
        }
        i++;
    }
    return (0);
}

int ft_real_index_a(t_data *nb, int nbr)//return the real index of a
{
    int i;

    i = 0;
    while (i < nb->stack_a->count)
    {
        if (nb->stack_a->tab[i] == nbr)
            return(i);
        i++;
    }
    return (0);
}

int ft_index_b(t_data *nb, int nbr)//return the mv_count
{
    int i;

    i = 0;
    while (i < nb->stack_b->count)
    {
        if (nb->stack_b->tab[i] == nbr)
        {
            if (i <= nb->stack_b->count / 2)
                return (i);
            else
                return (nb->stack_b->count - i);
        }
        i++;
    }
    return (0);
}

int ft_real_index_b(t_data *nb, int nbr)//return the real index of b
{
    int i;

    i = 0;
    while (i < nb->stack_b->count)
    {
        if (nb->stack_b->tab[i] == nbr)
            return (i);
        i++;
    }
    return (0);
}

int ft_search_next_a(t_data *nb, int nbr)//the closest superior to a in b
{
    int i;
    int next;

    i = 0;
    next = MAX;
    while (i < nb->stack_b->count)
    {
        if (nb->stack_b->tab[i] < next && nb->stack_b->tab[i] > nbr)
            next = nb->stack_b->tab[i];
        i++;
    }
    return (next);
}

int ft_search_next_b(t_data *nb, int nbr)// the closest superior to b in a
{
    int i;
    int next;

    i = 0;
    next = MAX;
    while (i < nb->stack_a->count)
    {
        if (nb->stack_a->tab[i] < next && nb->stack_a->tab[i] > nbr)
            next = nb->stack_a->tab[i];
        i++;
    }
    return (next);
}

void ft_top_top(t_data *nb, int nbr)
{
    while (nb->stack_b->tab[0] != nbr && nb->stack_a->tab[0] != ft_search_next_b(nb, nbr))
        ft_rr(nb);
    while (nb->stack_b->tab[0] == nbr && nb->stack_a->tab[0] != ft_search_next_b(nb, nbr))
        ft_ra(nb);
    while (nb->stack_b->tab[0] != nbr && nb->stack_a->tab[0] == ft_search_next_b(nb, nbr))
        ft_rb(nb);
}

void ft_bot_bot(t_data *nb, int nbr)
{
    while (nb->stack_b->tab[0] != nbr && nb->stack_a->tab[0] != ft_search_next_b(nb, nbr))
        ft_rrr(nb);
    while (nb->stack_b->tab[0] == nbr && nb->stack_a->tab[0] != ft_search_next_b(nb, nbr))
        ft_rra(nb);
    while (nb->stack_b->tab[0] != nbr && nb->stack_a->tab[0] == ft_search_next_b(nb, nbr))
        ft_rrb(nb);
}

void ft_bot_top(t_data *nb, int nbr)
{
    while (nb->stack_b->tab[0] != nbr)
        ft_rrb(nb);
    while (nb->stack_a->tab[0] != ft_search_next_b(nb, nbr))
        ft_ra(nb);
}

void ft_top_bot(t_data *nb, int nbr)
{
    while (nb->stack_b->tab[0] != nbr)
        ft_rb(nb);
    while (nb->stack_a->tab[0] != ft_search_next_b(nb, nbr))
        ft_rra(nb);
}

int ft_best_mv(t_data *nb)
{
    int i;
    int count_mv;
    int nbr;
    int index;
    
    i = 0;
    count_mv = MAX;
    index = 0;
    nbr = 0;
    while (i < nb->stack_b->count)
    {
        // printf ("the closet sup to [%d] is [%d]\n", nb->stack_b->tab[i], ft_search_next_b(nb, nb->stack_b->tab[i]));
        // printf ("and their index is %d and %d\n", ft_index_b(nb, nb->stack_b->tab[i]), ft_index_a(nb, ft_search_next_b(nb, nb->stack_b->tab[i])));
        if (ft_index_b(nb, nb->stack_b->tab[i]) + ft_index_a(nb, ft_search_next_b(nb, nb->stack_b->tab[i])) < count_mv)
        {
            count_mv = ft_index_b(nb, nb->stack_b->tab[i]) + ft_index_a(nb, ft_search_next_b(nb, nb->stack_b->tab[i]));
            index = i;//saving his index if the moves are lesser
            // printf("\n%d     %d\n", count_mv, index);
        }
        i++;
    }
    nbr = nb->stack_b->tab[index];//saving the nbr
    return (nbr);
}