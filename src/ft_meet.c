/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:02:29 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/19 14:04:27 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_top_top(t_data *nb, int nbr)
{
	while (nb->stack_b->tab[0] != nbr
		&& nb->stack_a->tab[0] != ft_search_next_b(nb, nbr))
		ft_rr(nb);
	while (nb->stack_b->tab[0] == nbr
		&& nb->stack_a->tab[0] != ft_search_next_b(nb, nbr))
		ft_ra(nb);
	while (nb->stack_b->tab[0] != nbr
		&& nb->stack_a->tab[0] == ft_search_next_b(nb, nbr))
		ft_rb(nb);
}

void	ft_bot_bot(t_data *nb, int nbr)
{
	while (nb->stack_b->tab[0] != nbr
		&& nb->stack_a->tab[0] != ft_search_next_b(nb, nbr))
		ft_rrr(nb);
	while (nb->stack_b->tab[0] == nbr
		&& nb->stack_a->tab[0] != ft_search_next_b(nb, nbr))
		ft_rra(nb);
	while (nb->stack_b->tab[0] != nbr
		&& nb->stack_a->tab[0] == ft_search_next_b(nb, nbr))
		ft_rrb(nb);
}

void	ft_bot_top(t_data *nb, int nbr)
{
	while (nb->stack_b->tab[0] != nbr)
		ft_rrb(nb);
	while (nb->stack_a->tab[0] != ft_search_next_b(nb, nbr))
		ft_ra(nb);
}

void	ft_top_bot(t_data *nb, int nbr)
{
	while (nb->stack_b->tab[0] != nbr)
		ft_rb(nb);
	while (nb->stack_a->tab[0] != ft_search_next_b(nb, nbr))
		ft_rra(nb);
}
