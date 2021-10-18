/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:44:24 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/18 18:49:55 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
	
	// for (int i = 0; i < nb->stack_a->count; i++)
	// 	printf("[%d]", nb->stack_a->tab[i]);
	// printf(" -----> ");
	// for (int i = 0; i < nb->stack_b->count; i++)
	// 	printf("[%d]", nb->stack_b->tab[i]);
	// printf("\n");
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
	
	// for (int i = 0; i < nb->stack_a->count; i++)
	// 	printf("[%d]", nb->stack_a->tab[i]);
	// printf(" -----> ");
	// for (int i = 0; i < nb->stack_b->count; i++)
	// 	printf("[%d]", nb->stack_b->tab[i]);
	// printf("\n");
}

void	ft_rr(t_data *nb)
{
	int	i;
	int j;
	int tempa;
	int tempb;

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
	// for (int i = 0; i < nb->stack_a->count; i++)
	// 	printf("[%d]", nb->stack_a->tab[i]);
	// printf(" -----> ");
	// for (int i = 0; i < nb->stack_b->count; i++)
	// 	printf("[%d]", nb->stack_b->tab[i]);
	// printf("\n");
}
