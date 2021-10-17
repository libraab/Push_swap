/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:37:43 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/15 16:13:42 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_solve_3a(t_data *nb)
{
	if ((nb->stack_a->tab[0] == ft_search_min(nb, 0)) && (nb->stack_a->tab[2] == ft_search_max(nb, 0)))
		return (1);
	if (nb->stack_a->tab[0] == ft_search_max(nb, 0) && nb->stack_a->tab[2] == ft_search_min(nb, 0))
	{
		ft_ra(nb);
		if (ft_2b_not_sorted(nb) == true)
			ft_ss(nb);
		else
			ft_sa(nb);
	}
	if (nb->stack_a->tab[0] == ft_search_max(nb, 0) && nb->stack_a->tab[1] == ft_search_min(nb, 0))
		ft_ra(nb);
	if (nb->stack_a->tab[0] == ft_search_min(nb, 0) && nb->stack_a->tab[1] == ft_search_max(nb, 0))
	{
		if (ft_2b_not_sorted(nb) == true)
			ft_ss(nb);
		else
			ft_sa(nb);
		ft_ra(nb);
	}
	if (nb->stack_a->tab[1] == ft_search_max(nb, 0) && nb->stack_a->tab[2] == ft_search_min(nb, 0))
		ft_rra(nb);
	if (nb->stack_a->tab[2] == ft_search_max(nb, 0) && nb->stack_a->tab[1] == ft_search_min(nb, 0))
	{
		if (ft_2b_not_sorted(nb) == true)
			ft_ss(nb);
		else
			ft_sa(nb);
	}
	return (1);
}

int	ft_solve_3b(t_data *nb)
{
	if ((nb->stack_b->tab[0] == ft_search_max(nb, 1)) && (nb->stack_b->tab[2] == ft_search_min(nb, 1)))
		return (1);
	else if (nb->stack_b->tab[0] == ft_search_max(nb, 1) && nb->stack_b->tab[1] == ft_search_min(nb, 1))
	{
		ft_rrb(nb);
		if (ft_2a_not_sorted(nb) == true)
			ft_ss(nb);
		else
			ft_sb(nb);
	}
	else if (nb->stack_b->tab[0] == ft_search_min(nb, 1) && nb->stack_b->tab[1] == ft_search_max(nb, 1))
		ft_rb(nb);
	else if (nb->stack_b->tab[0] == ft_search_min(nb, 1) && nb->stack_b->tab[2] == ft_search_max(nb, 1))
	{
		if (ft_2a_not_sorted(nb) == true)
			ft_ss(nb);
		else
			ft_sb(nb);
		ft_rrb(nb);
	}
	else if (nb->stack_b->tab[1] == ft_search_max(nb, 1) && nb->stack_b->tab[2] == ft_search_min(nb, 1))
	{
		if (ft_2a_not_sorted(nb) == true)
			ft_ss(nb);
		else
			ft_sb(nb);
	}
	else if (nb->stack_b->tab[1] == ft_search_min(nb, 1) && nb->stack_b->tab[2] == ft_search_max(nb, 1))
		ft_rrb(nb);
	return (1);
}