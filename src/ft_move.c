/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:32:50 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/21 13:57:46 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
	printf("pa\n");
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
	printf("pb\n");
	nb->moves++;
}

void	ft_ra(t_data *nb)
{
	int	temp;
	int	i;

	i = 0;
	temp = nb->stack_a->tab[0];
	while (i++ < nb->stack_a->count - 1)
		nb->stack_a->tab[i - 1] = nb->stack_a->tab[i];
	nb->stack_a->tab[i - 1] = temp;
	printf("ra\n");
	nb->moves++;
}

void	ft_rb(t_data *nb)
{
	int	i;
	int	temp;

	i = 0;
	temp = nb->stack_b->tab[0];
	while (i++ < nb->stack_b->count - 1)
		nb->stack_b->tab[i - 1] = nb->stack_b->tab[i];
	nb->stack_b->tab[i - 1] = temp;
	printf("rb\n");
	nb->moves++;
}

void	ft_rr(t_data *nb)
{
	int	i;
	int	j;
	int	tempa;
	int	tempb;

	i = 0;
	j = 0;
	tempa = nb->stack_a->tab[0];
	tempb = nb->stack_b->tab[0];
	while (i++ < nb->stack_a->count - 1)
		nb->stack_a->tab[i - 1] = nb->stack_a->tab[i];
	nb->stack_a->tab[i - 1] = tempa;
	while (j++ < nb->stack_b->count - 1)
		nb->stack_b->tab[j - 1] = nb->stack_b->tab[j];
	nb->stack_b->tab[j - 1] = tempb;
	printf("rr\n");
	nb->moves++;
}
