/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:49:49 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/19 17:41:48 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/push_swap.h"

void	ft_pa(t_data *nb)
{
	int	i;
	int	x;
	int	temp;

	i = 0;
	x = nb->stack_a->count;
	temp = nb->stack_b->tab[0];
	while (i < nb->stack_b->count - 1)
	{
		nb->stack_b->tab[i] = nb->stack_b->tab[i + 1];
		i++;
	}
	while (x >= 0)
	{
		nb->stack_a->tab[x + 1] = nb->stack_a->tab[x];
		x--;
	}
	nb->stack_a->tab[0] = temp;
	nb->stack_a->count++;
	nb->stack_b->count--;
	nb->moves++;
}

void	ft_pb(t_data *nb)
{
	int	i;
	int	x;
	int	temp;

	i = 0;
	x = nb->stack_b->count;
	temp = nb->stack_a->tab[0];
	while (i < nb->stack_a->count - 1)
	{
		nb->stack_a->tab[i] = nb->stack_a->tab[i + 1];
		i++;
	}
	while (x >= 0)
	{
		nb->stack_b->tab[x + 1] = nb->stack_b->tab[x];
		x--;
	}
	nb->stack_b->tab[0] = temp;
	nb->stack_b->count++;
	nb->stack_a->count--;
	nb->moves++;
}

void	ft_sa(t_data *nb)
{
	int	temp;

	temp = nb->stack_a->tab[0];
	nb->stack_a->tab[0] = nb->stack_a->tab[1];
	nb->stack_a->tab[1] = temp;
	nb->moves++;
}

void	ft_sb(t_data *nb)
{
	int	temp;

	temp = nb->stack_b->tab[0];
	nb->stack_b->tab[0] = nb->stack_b->tab[1];
	nb->stack_b->tab[1] = temp;
	nb->moves++;
}

void	ft_ss(t_data *nb)
{
	int	tempa;
	int	tempb;

	tempa = nb->stack_a->tab[0];
	tempb = nb->stack_b->tab[0];
	nb->stack_a->tab[0] = nb->stack_a->tab[1];
	nb->stack_a->tab[1] = tempa;
	nb->stack_b->tab[0] = nb->stack_b->tab[1];
	nb->stack_b->tab[1] = tempb;
	nb->moves++;
}
