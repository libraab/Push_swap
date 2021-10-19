/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:50:08 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/19 17:42:02 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/push_swap.h"

void	ft_ra(t_data *nb)
{
	int	temp;
	int	i;

	i = 0;
	temp = nb->stack_a->tab[0];
	while (i++ < nb->stack_a->count - 1)
		nb->stack_a->tab[i - 1] = nb->stack_a->tab[i];
	nb->stack_a->tab[i - 1] = temp;
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
	nb->moves++;
}
