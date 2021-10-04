/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:53:21 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/04 12:27:00 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int ft_search_max(t_data *nb, int x)
{
    int i;

    i = 0;
    if (x = 0)
    {
        nb->stack_a->max = nb->stack_a->tab[i];
        while (i < nb->stack_a->count - 1)
        {
			if (nb->stack_a->tab[i] > nb->stack_a->max)
				nb->stack_a->max = nb->stack_a->tab[i];
            i++;
        }
    }
	i = 0;
	if (x = 1)
    {
        nb->stack_b->max = nb->stack_b->tab[i];
        while (i < nb->stack_b->count - 1)
        {
			if (nb->stack_b->tab[i] > nb->stack_b->max)
				nb->stack_b->max = nb->stack_b->tab[i];
            i++;
        }
    }
	return (1);
}

int ft_search_min(t_data *nb, int x)
{
    int i;

    i = 0;
    if (x = 0)
    {
        nb->stack_a->min = nb->stack_a->tab[i];
        while (i < nb->stack_a->count - 1)
        {
			if (nb->stack_a->tab[i] > nb->stack_a->min)
				nb->stack_a->min = nb->stack_a->tab[i];
            i++;
        }
    }
	i = 0;
	if (x = 1)
    {
        nb->stack_b->min = nb->stack_b->tab[i];
        while (i < nb->stack_b->count - 1)
        {
			if (nb->stack_b->tab[i] > nb->stack_b->min)
				nb->stack_b->min = nb->stack_b->tab[i];
            i++;
        }
    }
	return (1);
}

ft_solve_more(t_data *nb)
{
    
}