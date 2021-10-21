/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:18:39 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/21 12:20:40 by abouhlel         ###   ########.fr       */
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

void	ft_transfert(t_data *nb)
{
	int	i;

	i = 0;
	nb->stack_a->count = nb->tot;
	nb->stack_b->count = 0;
	nb->moves = 0;
	nb->stack_a->tab = malloc (sizeof (int) * nb->tot);
	nb->stack_b->tab = malloc (sizeof (int) * nb->tot);
	while (i < nb->tot)
	{
		nb->stack_a->tab[i] = nb->initial_tab[i];
		i++;
	}
}

void	ft_solve(t_data *nb)
{
	nb->stack_a = malloc(sizeof(t_stack));
	nb->stack_b = malloc(sizeof(t_stack));
	ft_transfert(nb);
	if (nb->tot == 2)
		ft_solve_2(nb);
	if (nb->tot == 3)
		ft_solve_3(nb);
	if (nb->tot > 3)
		ft_big_algo(nb);
}
