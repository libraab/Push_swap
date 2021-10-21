/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:55:54 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/21 13:57:28 by abouhlel         ###   ########.fr       */
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
	while (i > 0)
	{
		nb->stack_a->tab[i] = nb->stack_a->tab[i - 1];
		i--;
	}
	nb->stack_a->tab[0] = temp;
	printf("rra\n");
	nb->moves++;
}

void	ft_rrb(t_data *nb)
{
	int	temp;
	int	i;

	temp = 0;
	i = nb->stack_b->count - 1;
	temp = nb->stack_b->tab[i];
	while (i > 0)
	{
		nb->stack_b->tab[i] = nb->stack_b->tab[i - 1];
		i--;
	}
	nb->stack_b->tab[0] = temp;
	printf("rrb\n");
	nb->moves++;
}

void	ft_rrr(t_data *nb)
{
	int	i;
	int	tempa;
	int	tempb;

	i = nb->stack_a->count - 1;
	tempa = nb->stack_a->tab[i];
	while (i > 0)
	{
		nb->stack_a->tab[i] = nb->stack_a->tab[i - 1];
		i--;
	}
	nb->stack_a->tab[0] = tempa;
	i = nb->stack_b->count - 1;
	tempb = nb->stack_b->tab[i];
	while (i > 0)
	{
		nb->stack_b->tab[i] = nb->stack_b->tab[i - 1];
		i--;
	}
	nb->stack_b->tab[0] = tempb;
	printf("rrr\n");
	nb->moves++;
}

void	ft_sa(t_data *nb)
{
	int	temp;

	temp = nb->stack_a->tab[0];
	nb->stack_a->tab[0] = nb->stack_a->tab[1];
	nb->stack_a->tab[1] = temp;
	printf("sa\n");
	nb->moves++;
}

void	ft_sb(t_data *nb)
{
	int	temp;

	temp = nb->stack_b->tab[0];
	nb->stack_b->tab[0] = nb->stack_b->tab[1];
	nb->stack_b->tab[1] = temp;
	printf("sb\n");
	nb->moves++;
}
