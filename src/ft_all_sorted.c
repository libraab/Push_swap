/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:51:45 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/18 09:42:28 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_all_sorted(t_data *nb, int x)
{
	int	i;
	i = 0;
	if (x == 0)
	{
		while (i + 1 < nb->tot)
		{
			if (nb->stack_a->tab[i] > nb->stack_a->tab[i + 1])
				return (0);
			i++;
		}
		return (1);
	}
	if (x == 1)
	{
		while (i + 1 < nb->tot)
		{
			if (nb->stack_b->tab[i] > nb->stack_b->tab[i + 1])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	ft_stack_sorted(t_data *nb, int count, int x)
{
	int	i;

	i = 0;
	if (x == 0)
	{
		while (i + 1 < count)
		{
			if (nb->stack_a->tab[i] < nb->stack_a->tab[i + 1])
				i++;
			else
				return (0);
		}
		//**********************************************
		//printing the final tab
		// printf("\nsorted a is --> ");
		// for (int i = 0; i < nb->stack_a->count; i++)
		// 	printf("| %d |", nb->stack_a->tab[i]);
		//**********************************************
	}
	if (x == 1) 
	{
		while (i + 1 < count)
		{
			if (nb->stack_b->tab[i] < nb->stack_b->tab[i + 1])
				i++;
			else
				return (0);
		}
		//**********************************************
		//printing the final tab
		// printf("\nsorted b is --> ");
		// for (int i = 0; i < nb->stack_b->count; i++)
		// 	printf("| %d |", nb->stack_b->tab[i]);
		//**********************************************
	}
	return (1);
}
