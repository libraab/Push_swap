/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 08:27:44 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/04 09:30:06 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_check_sorted(t_stack *stack_x, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (stack_x->tab[i] < stack_x->tab[i + 1])
			i++;
		else
			return (0);
	}
	//****************************************
	//printing the final tab
	printf("sorted tab is --> ");
	for (int i = 0; i < x; i++)
		printf("|   %d   ", stack_x->tab[i]);
	//****************************************
	return (1);
}
