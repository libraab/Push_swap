/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 08:44:30 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/21 12:11:47 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_push_a(t_data *nb)
{
	int	max;

	max = ft_search_max(nb);
	while (nb->stack_a->count > 2)
	{
		if (nb->stack_a->tab[0] == max)
			ft_ra(nb);
		else
			ft_pb(nb);
	}
	return (1);
}

int	ft_topbot(t_data *nb, int nbr)
{
	if ((ft_real_index_b(nb, nbr) <= nb->stack_b->count / 2)
		&& (ft_real_index_a(nb, ft_search_next_b(nb, nbr))
			<= nb->stack_a->count / 2))
		ft_top_top(nb, nbr);
	if ((ft_real_index_b(nb, nbr) > nb->stack_b->count / 2)
		&& (ft_real_index_a(nb, ft_search_next_b(nb, nbr))
			> nb->stack_a->count / 2))
		ft_bot_bot(nb, nbr);
	if ((ft_real_index_b(nb, nbr) <= nb->stack_b->count / 2)
		&& (ft_real_index_a(nb, ft_search_next_b(nb, nbr))
			> nb->stack_a->count / 2))
		ft_top_bot(nb, nbr);
	if ((ft_real_index_b(nb, nbr) > nb->stack_b->count / 2)
		&& (ft_real_index_a(nb, ft_search_next_b(nb, nbr))
			<= nb->stack_a->count / 2))
		ft_bot_top(nb, nbr);
	return (nbr);
}

int	ft_swing(t_data *nb)
{
	while (nb->stack_a->tab[0] != ft_search_min(nb))
	{
		if (ft_real_index_a (nb, ft_search_min(nb)) > nb->stack_a->count / 2)
			ft_rra(nb);
		else
			ft_ra(nb);
	}
	return (1);
}

int	ft_big_algo(t_data *nb)
{
	int	nbr;
	int	i;

	i = 0;
	ft_push_a(nb);
	while (nb->stack_a->count > 1 && nb->stack_b->count > 0)
	{
		nbr = ft_best_option_b(nb);
		while ((nb->stack_b->tab[0] != nbr)
			|| nb->stack_a->tab[0] != ft_search_next_b(nb, nbr))
			ft_topbot(nb, nbr);
		if (nb->stack_b->tab[0] == nbr && nb->stack_a->tab[0]
			== ft_search_next_b(nb, nbr))
			ft_pa(nb);
	}
	ft_swing(nb);
	return (1);
}
