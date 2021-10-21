/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:23:58 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/21 12:10:31 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_index_b(t_data *nb, int nbr)
{
	int	i;

	i = 0;
	while (i < nb->stack_b->count)
	{
		if (nb->stack_b->tab[i] == nbr)
		{
			if (i <= nb->stack_b->count / 2)
				return (i);
			else
				return (nb->stack_b->count - i);
		}
		i++;
	}
	return (0);
}

int	ft_real_index_b(t_data *nb, int nbr)
{
	int	i;

	i = 0;
	while (i < nb->stack_b->count)
	{
		if (nb->stack_b->tab[i] == nbr)
			return (i);
		i++;
	}
	return (0);
}

int	ft_best_option_b(t_data *nb)
{
	int	i;
	int	count_mv;
	int	nbr;
	int	index;

	i = 0;
	count_mv = MAX;
	index = 0;
	nbr = 0;
	while (i < nb->stack_b->count)
	{
		if (ft_index_b(nb, nb->stack_b->tab[i])
			+ ft_index_a(nb, ft_search_next_b(nb, nb->stack_b->tab[i]))
			< count_mv)
		{
			count_mv = ft_index_b(nb, nb->stack_b->tab[i])
				+ ft_index_a(nb, ft_search_next_b(nb, nb->stack_b->tab[i]));
			index = i;
		}
		i++;
	}
	nbr = nb->stack_b->tab[index];
	return (nbr);
}
