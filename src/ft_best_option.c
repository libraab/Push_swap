/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 09:24:51 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/17 17:39:13 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int ft_best_option(t_data *nb, int max1, int max2)
{
    int index1;
    int index2;
    int i;
    int x;

    i = 0;
    index1 = 0;
    index2 = 0;
    x = nb->stack_b->count;
    while (i < x)
    {
        if (nb->stack_b->tab[i] == max1)
        {
            if (i <= (nb->stack_b->count / 2))
                index1 = i;
            else
                index1 = nb->stack_b->count - i;
        }
        if (nb->stack_b->tab[i] == max2)
        {
            if (i <= (nb->stack_b->count / 2))
                index2 = i;
            else
                index2 = nb->stack_b->count - i;
        }
        i++;
    }
    if (index1 <= index2)
        return (1);
    return (0);
}

int ft_best_optiona(t_data *nb, int min1, int min2)
{
    int index1;
    int index2;
    int i;
    int x;

    i = 0;
    index1 = 0;
    index2 = 0;
    x = nb->stack_a->count;
    while (i < x)
    {
        if (nb->stack_a->tab[i] == min1)
        {
            if (i <= (nb->stack_a->count / 2))
                index1 = i;
            else
                index1 = nb->stack_a->count - i;
        }
        if (nb->stack_a->tab[i] == min2)
        {
            if (i <= (nb->stack_a->count / 2))
                index2 = i;
            else
                index2 = nb->stack_a->count - i;
        }
        i++;
    }
    if (index1 <= index2)
        return (1);
    return (0);
}

int ft_best_move(t_data *nb, int x)
{
    int i;
    int y;

    i = 0;
    y = nb->stack_b->count;
    while (i < y)
    {
        if (nb->stack_b->tab[i] == x)
        {
            if (i <= (nb->stack_b->count / 2))
                return (1); //rb
            else
                return (0); //rrb
        }
        i++;
    }
    return (-1);
}

int ft_best_movea(t_data *nb, int x)
{
    int i;
    int y;

    i = 0;
    y = nb->stack_a->count;
    while (i < y)
    {
        if (nb->stack_a->tab[i] == x)
        {
            if (i <= (nb->stack_a->count / 2))
                return (1); //rb
            else
                return (0); //rrb
        }
        i++;
    }
    return (-1);
}