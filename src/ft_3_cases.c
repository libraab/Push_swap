/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:37:41 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/06 19:37:09 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_3_cases(t_data *nb, int x)
{
	int	i;

	if (x == 0)
	{
		i = nb->stack_a->count;
		//printf("*****%d*****%d******%d\n", nb->stack_a->tab[i - 3], nb->stack_a->tab[i - 2], nb->stack_a->tab[i - 1]);
		if (nb->stack_a->tab[i - 3] == ft_search_max(nb, 0) && nb->stack_a->tab[i - 2] == ft_search_min(nb, 0))
			return (1);// ra
		if (nb->stack_a->tab[i - 1] == ft_search_min(nb, 0) && nb->stack_a->tab[i - 2] == ft_search_max(nb, 0))
			return (2); //rra
		if (nb->stack_a->tab[i - 2] == ft_search_min(nb, 0) && nb->stack_a->tab[i - 1] == ft_search_max(nb, 0))
			return (3);//sa
		if (nb->stack_a->tab[i - 3] == ft_search_min(nb, 0) && nb->stack_a->tab[i - 1] == ft_search_max(nb, 0))
			return (4);//sorted
		else
			return (0);
	}
	if (x == 1)
	{
		i = nb->stack_b->count;
		//printf("*****%d*****%d******%d\n", nb->stack_b->tab[i - 3], nb->stack_b->tab[i - 2], nb->stack_b->tab[i - 1]);
		if (nb->stack_b->tab[i - 3] == ft_search_max(nb, 1) && nb->stack_b->tab[i - 2] == ft_search_min(nb, 1))
			return (1);// ra
		if (nb->stack_b->tab[i - 1] == ft_search_min(nb, 1) && nb->stack_b->tab[i - 2] == ft_search_max(nb, 1))
			return (2); //rra
		if (nb->stack_b->tab[i - 2] == ft_search_min(nb, 1) && nb->stack_b->tab[i - 1] == ft_search_max(nb, 1))
			return (3);//sa
		if (nb->stack_b->tab[i - 3] == ft_search_min(nb, 1) && nb->stack_b->tab[i - 1] == ft_search_max(nb, 1))
			return (4);//sorted
		else
			return (0);
	}
	return (0);
}
