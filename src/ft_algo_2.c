/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:59:04 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/17 15:58:06 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

bool	ft_2a_not_sorted(t_data *nb)
{
	if (nb->stack_a->tab[0] > nb->stack_a->tab[1])
		return (true);//yes a is NOOOOT sorted
	return (false);//no a is sorted
}

bool	ft_2b_not_sorted(t_data *nb)
{
	if (nb->stack_b->tab[0] < nb->stack_b->tab[1])
		return (true);//b is NOOOOT sorted
	return (false);//b is sorted
}

int	ft_solve_2(t_data *nb)
{
	ft_sa(nb);
	return (1);
}

int    ft_swap_top(t_data *nb)
{
    if ((nb->stack_a->tab[0] > nb->stack_a->tab[1]) && (nb->stack_b->tab[1] > nb->stack_b->tab[0]))
		ft_ss(nb);
    else if (nb->stack_a->tab[0] > nb->stack_a->tab[1])
        ft_sa(nb);
    else if (nb->stack_b->tab[0] < nb->stack_b->tab[1])
        ft_sb(nb);
    return (1);
}

bool	ft_rotate_both(t_data *nb)
{
	if ((nb->stack_a->tab[0] > nb->stack_a->tab[nb->stack_a->count - 1]) && (nb->stack_b->tab[0] < nb->stack_b->tab[nb->stack_b->count - 1]))
		return (true);
	else
		return (false);
}

bool	ft_reverse_rotate_both(t_data *nb)
{
	if ((nb->stack_a->tab[nb->stack_a->count - 1] < nb->stack_a->tab[0]) && (nb->stack_b->tab[nb->stack_b->count - 1] > nb->stack_a->tab[0]))
		return (true);
	else
		return (false);
}