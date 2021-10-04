/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:44:24 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/04 09:05:09 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_ra(t_data *nb)
{
	int	temp;
	int	i;

	i = 0;
	temp = nb->stack_a->tab[0];
	while (i < nb->tot - 1)
	{
		nb->stack_a->tab[i] = nb->stack_a->tab[i + 1];
		i++;
	}
	nb->stack_a->tab[i] = temp;
	printf("ra\n");
}

void	ft_rb(t_data *nb)
{
	int	i;
	int	temp;

	i = 1;
	temp = nb->stack_b->tab[0];
	while (i < nb->tot - 1)
	{
		nb->stack_b->tab[i] = nb->stack_b->tab[i + 1];
		i++;
	}
	nb->stack_b->tab[i] = temp;
	printf("rb\n");
}

void	ft_rr(t_data *nb)
{
	int	i;
	int	tempa;
	int	tempb;

	i = 0;
	tempa = nb->stack_a->tab[0];
	tempb = nb->stack_b->tab[0];
	while (i < nb->tot - 1)
	{
		nb->stack_a->tab[i] = nb->stack_a->tab[i + 1];
		nb->stack_b->tab[i] = nb->stack_b->tab[i + 1];
		i++;
	}
	nb->stack_a->tab[i] = tempa;
	nb->stack_b->tab[i] = tempb;
	printf("rr\n");
}
