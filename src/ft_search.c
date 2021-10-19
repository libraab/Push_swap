/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:25:55 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/19 14:01:44 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_search_max(t_data *nb)
{
	int	i;

	i = 0;
	nb->stack_a->max = nb->stack_a->tab[i];
	while (i < nb->stack_a->count)
	{
		if (nb->stack_a->tab[i] > nb->stack_a->max)
			nb->stack_a->max = nb->stack_a->tab[i];
		i++;
	}
	return (nb->stack_a->max);
}

int	ft_search_min(t_data *nb)
{
	int	i;

	i = 0;
	nb->stack_a->min = nb->stack_a->tab[i];
	while (i < nb->stack_a->count)
	{
		if (nb->stack_a->tab[i] < nb->stack_a->min)
			nb->stack_a->min = nb->stack_a->tab[i];
		i++;
	}
	return (nb->stack_a->min);
}

int	ft_search_next_a(t_data *nb, int nbr)
{
	int	i;
	int	next;

	i = 0;
	next = MAX;
	while (i < nb->stack_b->count)
	{
		if (nb->stack_b->tab[i] < next && nb->stack_b->tab[i] > nbr)
			next = nb->stack_b->tab[i];
		i++;
	}
	return (next);
}

int	ft_search_next_b(t_data *nb, int nbr)
{
	int	i;
	int	next;

	i = 0;
	next = MAX;
	while (i < nb->stack_a->count)
	{
		if (nb->stack_a->tab[i] < next && nb->stack_a->tab[i] > nbr)
			next = nb->stack_a->tab[i];
		i++;
	}
	return (next);
}
