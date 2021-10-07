/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 08:27:44 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/07 11:30:27 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
	if (x == 1) //have to be inverted !!!!!!!!!!!!!!!!!!
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
	printf("stack is sorted\n");
	return (1);
}
