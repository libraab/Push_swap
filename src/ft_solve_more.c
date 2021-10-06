/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:53:21 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/06 10:19:29 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int ft_search_max(t_data *nb, int x)
{
    int i;

    i = 0;
    if (x == 0)
    {
        nb->stack_a->max = nb->stack_a->tab[i];
        while (i < nb->stack_a->count)
        {
			if (nb->stack_a->tab[i] > nb->stack_a->max)
				nb->stack_a->max = nb->stack_a->tab[i];
            i++;
        }
        return (nb->stack_a->max);
    }
	if (x == 1)
    {
        nb->stack_b->max = nb->stack_b->tab[i];
        while (i < nb->stack_b->count)
        {
			if (nb->stack_b->tab[i] > nb->stack_b->max)
				nb->stack_b->max = nb->stack_b->tab[i];
            i++;
        }
        return (nb->stack_b->max);
    }
    return (1);
}

int ft_search_min(t_data *nb, int x)
{
    int i;

    i = 0;
    if (x == 0)
    {
        nb->stack_a->min = nb->stack_a->tab[i];
        while (i < nb->stack_a->count)
        {
			if (nb->stack_a->tab[i] < nb->stack_a->min)
				nb->stack_a->min = nb->stack_a->tab[i];
            i++;
        }
        return (nb->stack_a->min);
    }
	if (x == 1)
    {
        nb->stack_b->min = nb->stack_b->tab[i];
        while (i < nb->stack_b->count)
        {
			if (nb->stack_b->tab[i] < nb->stack_b->min)
				nb->stack_b->min = nb->stack_b->tab[i];
            i++;
        }
        return (nb->stack_b->min);
    }
    return (1);
}

int ft_solve_more(t_data *nb)
{
    int i;

    while (nb->stack_a->count > 3)
    {
        i = 0;
        while (nb->stack_a->tab[i] != ft_search_min(nb, 0))
            i++;
        while ((nb->tot - i) < 3 && nb->stack_a->tab[0] != ft_search_min(nb, 0))
            ft_rra(nb);
        while ((nb->tot - i) >= 3 && nb->stack_a->tab[0] != ft_search_min(nb, 0))
        {
            if (ft_3_cases(nb, 0) == 0)
                ft_ra(nb);
            else
                ft_sa(nb);
        }
        if (nb->stack_a->tab[0] == ft_search_min(nb, 0))
            ft_pb(nb);
    }
    if (nb->stack_a->count == 3)
    {
        //printf("%d\n", ft_3_cases(nb, 0));
        ft_solve_3(nb);
    }
    while (nb->stack_b->count > 0)
        ft_pa(nb);
    return (1);
}
int ft_solve_more2(t_data *nb)//secomd strategy
{
    int i;

    i = 0;
    while (nb->stack_a->count > 3 )
    {
        //printf("********%d *******%d\n", nb->stack_a->tab[0], ft_search_min(nb, 0));
        if (nb->stack_a->tab[0] == ft_search_min(nb, 0))
            ft_pb(nb);
        if (nb->stack_a->tab[1] == ft_search_min(nb, 0))
        {
            ft_sa(nb);
            ft_pb(nb);
        }
        if (nb->stack_a->tab[nb->stack_a->count - 1] == ft_search_min(nb, 0))
            ft_rra(nb);
        // if (nb->stack_a->tab[nb->stack_a->count - 2] == ft_search_min(nb, 0))
        // {
        //     ft_rra(nb);
        //     ft_rra(nb);
        // } 
        else
            ft_pb(nb);
    }
    ft_solve_3(nb);
    // if (ft_3_cases(nb, 0) == 3 && (nb->stack_b->tab[0] < nb->stack_b->tab[1]))
    //     ft_ss(nb);
    // if (ft_3_cases(nb, 0) == 1 && (nb->stack_b->tab[0] < nb->stack_b->tab[1]))
    //     ft_rr(nb);
    // if (ft_3_cases(nb, 0) == 2 && (nb->stack_b->tab[0] < nb->stack_b->tab[1]))
    //     ft_rrr(nb);
    while (nb->stack_b->count > 0)
    {
        ft_pa(nb);
        if (nb->stack_a->tab[0] > nb->stack_a->tab[nb->stack_a->count - 1])
            ft_ra(nb);
        if (nb->stack_a->tab[0] > nb->stack_a->tab[1])
            ft_sa(nb);
    }
    if (nb->stack_a->tab[0] > nb->stack_a->tab[1])
    {
        printf("here\n");
        ft_sa(nb);
    }
    return (1);
    
    
}