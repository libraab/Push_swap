/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:53:21 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/06 19:26:33 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/*int ft_solve_more(t_data *nb)
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
}*/

// int ft_sending_min(t_data *nb)
// {
    
// }

// int ft_sending_max(t_data *nb)
// {
    
// }

int	ft_solve_more2(t_data *nb) //second strategy
{
    int i;

    i = 0;
    while ((nb->stack_a->count > 3 && (ft_check_sorted(nb, nb->stack_a->count, 0) == 0)))
    {
        //printf("********%d *******%d\n", nb->stack_a->tab[0], ft_search_min(nb, 0));
        // if (nb->stack_a->tab[0] == ft_search_min(nb, 0))
        //     ft_pb(nb);
        if (nb->stack_a->tab[0] == ft_search_max(nb, 0))
        {
            printf("in\n");
            ft_ra(nb);
            if (ft_check_sorted(nb, nb->stack_a->count, 0) == 1)
                return (1);
        }
        
        if (nb->stack_a->tab[1] == ft_search_min(nb, 0))
        {
            if (nb->stack_a->tab[0] == ft_search_max(nb, 0))
            	ft_ra(nb);
			else
			{
                ft_sa(nb);
                if (ft_check_sorted(nb, nb->stack_a->count, 0) == 1)
                    return (1);
            }
		}
		if (nb->stack_a->tab[nb->stack_a->count - 1] == ft_search_min(nb, 0))
		{
            ft_rra(nb);
            if (ft_check_sorted(nb, nb->stack_a->count, 0) == 1)
                return (1);
        }
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
		if (ft_check_sorted(nb, nb->stack_a->count, 0))
    		ft_pa(nb);
		if (nb->stack_a->tab[0] > nb->stack_a->tab[nb->stack_a->count - 1])
			ft_ra(nb);
		if (nb->stack_a->tab[0] > nb->stack_a->tab[1])
		{
			ft_sa(nb);
            printf("here\n");
			if (ft_check_sorted(nb, nb->stack_a->count, 0) == 1 && nb->stack_b->count > 0)
				ft_pa(nb);
			if ((nb->stack_a->tab[0] == ft_search_min(nb, 0)) && (ft_check_sorted(nb, nb->stack_a->count, 0) == 0))
			{
				ft_pb(nb);
				ft_solve_3(nb);
    		}
    	}
    }
    if ((nb->stack_a->tab[0] > nb->stack_a->tab[1]) && (nb->stack_a->tab[0] < nb->stack_a->tab[nb->stack_a->count - 1]))
    	ft_sa(nb);
    if ((nb->stack_a->tab[0] > nb->stack_a->tab[1]) && (nb->stack_a->tab[0] > nb->stack_a->tab[nb->stack_a->count - 1]))
    	ft_ra(nb);
    if (ft_check_sorted(nb, nb->stack_a->count, 0) == 0)
        ft_solve_more2(nb);
    
    return (1);
}
