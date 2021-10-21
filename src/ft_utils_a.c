/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:09:36 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/21 12:10:38 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_index_a(t_data *nb, int nbr)
{
	int	i;

	i = 0;
	while (i < nb->stack_a->count)
	{
		if (nb->stack_a->tab[i] == nbr)
		{
			if (i <= nb->stack_a->count / 2)
				return (i);
			else
				return (nb->stack_a->count - i);
		}
		i++;
	}
	return (0);
}

int	ft_real_index_a(t_data *nb, int nbr)
{
	int	i;

	i = 0;
	while (i < nb->stack_a->count)
	{
		if (nb->stack_a->tab[i] == nbr)
			return (i);
		i++;
	}
	return (0);
}

int	ft_best_option_a(t_data *nb)
{
	int	i;
	int	count_mv;
	int	nbr;
	int	index;

	i = 0;
	count_mv = MAX;
	index = 0;
	nbr = 0;
	while (i < nb->stack_a->count)
	{
		if (ft_index_a(nb, nb->stack_a->tab[i])
			+ ft_index_b(nb, ft_search_next_a(nb, nb->stack_a->tab[i]))
			< count_mv)
		{
			count_mv = ft_index_a(nb, nb->stack_a->tab[i])
				+ ft_index_b(nb, ft_search_next_a(nb, nb->stack_a->tab[i]));
			index = i;
		}
		i++;
	}
	nbr = nb->stack_a->tab[index];
	return (nbr);
}
