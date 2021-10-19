/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:37:43 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/19 14:27:18 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_solve_3(t_data *nb)
{
	if (nb->stack_a->tab[0] == ft_search_max(nb)
		&& nb->stack_a->tab[2] == ft_search_min(nb))
	{
		ft_ra(nb);
		ft_sa(nb);
	}
	if (nb->stack_a->tab[0] == ft_search_max(nb)
		&& nb->stack_a->tab[1] == ft_search_min(nb))
		ft_ra(nb);
	if (nb->stack_a->tab[0] == ft_search_min(nb)
		&& nb->stack_a->tab[1] == ft_search_max(nb))
	{
		ft_sa(nb);
		ft_ra(nb);
	}
	if (nb->stack_a->tab[1] == ft_search_max(nb)
		&& nb->stack_a->tab[2] == ft_search_min(nb))
		ft_rra(nb);
	if (nb->stack_a->tab[2] == ft_search_max(nb)
		&& nb->stack_a->tab[1] == ft_search_min(nb))
		ft_sa(nb);
	return (1);
}
