/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:32:50 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/29 15:13:02 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// void    ft_pa(t_data *nb)
// {
//     printf("pa\n");
// }

// void    ft_pb(t_data *nb)
// {
//     printf("pb\n");
// }

void    ft_sa(t_data *nb)
{
    int temp;
    
    temp = 0;
    temp = nb->stack_a->tab[0];
    nb->stack_a->tab[0] = nb->stack_a->tab[1];
    nb->stack_a->tab[1] = temp;
    printf("sa\n");
}

void    ft_sb(t_data *nb)
{
    int temp;
    
    temp = 0;
    temp = nb->stack_b->tab[0];
    nb->stack_b->tab[0] = nb->stack_b->tab[1];
    nb->stack_b->tab[1] = temp;
    printf("sb\n");
}

void    ft_ra(t_data *nb)
{
    int temp;
    int i;

    temp = 0;
    i = 0;
    temp = nb->stack_a->tab[0];
    while (i < nb->tot - 1)
    {
        nb->stack_a->tab[i] = nb->stack_a->tab[i + 1];
        i++;
    }
    nb->stack_a->tab[i] = temp;
    printf("ra\n");
}

void    ft_rb(t_data *nb)
{
    int i;
    int temp;

    i = 1;
    temp = 0;
    temp = nb->stack_b->tab[0];
    while (i < nb->tot - 1)
    {
        nb->stack_b->tab[i] = nb->stack_b->tab[i + 1];
        i++;
    }
    nb->stack_b->tab[i] = temp;
    printf("rb\n");
}

void    ft_rra(t_data *nb)
{
    int temp;
    int i;

    temp = 0;
    i = nb->tot - 1;
    temp = nb->stack_a->tab[i];
    while (i > 0)
    {
        nb->stack_a->tab[i] = nb->stack_a->tab[i - 1];
        i--;
    }
    nb->stack_a->tab[0] = temp;
    printf("rra\n");
}

void    ft_rrb(t_data *nb)
{
    int temp;
    int i;

    temp = 0;
    i = nb->tot - 1;
    temp = nb->stack_b->tab[i];
    while (i > 0)
    {
        nb->stack_b->tab[i] = nb->stack_b->tab[i - 1];
        i--;
    }
    nb->stack_b->tab[0] = temp;
    printf("rrb\n");
}

