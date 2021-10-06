/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:55:54 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/06 17:45:18 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_rra(t_data *nb)
{
	int	temp;
	int	i;

	temp = 0;
	i = nb->stack_a->count - 1;
	temp = nb->stack_a->tab[i];
	printf("%d        \n", i);
	while (i > 0)
	{
		printf("putting %d     in      %d    \n", nb->stack_a->tab[i - 1], nb->stack_a->tab[i]);
		nb->stack_a->tab[i] = nb->stack_a->tab[i - 1];
		i--;
	}
	nb->stack_a->tab[0] = temp;
	printf("rra\n");
	nb->moves++;
	for (int i = 0; i < nb->stack_a->count; i++)
        printf ("| %d |", nb->stack_a->tab[i]);
		printf("\n");
}

void	ft_rrb(t_data *nb)
{
	int	temp;
	int	i;

	temp = 0;
	i = nb->tot - 1;
	temp = nb->stack_b->tab[i];
	while (i > 0)
	{
		nb->stack_b->tab[i] = nb->stack_b->tab[i - 1];
		i--;
	}
	nb->stack_b->tab[0] = temp;
	printf("rrb\n");
	nb->moves++;
	for (int i = 0; i < nb->stack_a->count; i++)
        printf ("| %d |", nb->stack_a->tab[i]);
		printf("\n");
}

void	ft_rrr(t_data *nb)
{
	int	i;
	int	tempa;
	int	tempb;

	i = nb->tot - 1;
	tempa = nb->stack_a->tab[i];
	tempb = nb->stack_a->tab[i];
	while (i > 0)
	{
		nb->stack_a->tab[i] = nb->stack_a->tab[i - 1];
		nb->stack_b->tab[i] = nb->stack_b->tab[i - 1];
		i--;
	}
	nb->stack_a->tab[0] = tempa;
	nb->stack_b->tab[0] = tempb;
	printf("rrr\n");
	nb->moves++;
	for (int i = 0; i < nb->stack_a->count; i++)
        printf ("| %d |", nb->stack_a->tab[i]);
		printf("\n");
}
