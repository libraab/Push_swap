/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:44:24 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/05 19:31:14 by abouhlel         ###   ########.fr       */
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
	for (int i = 0; i < nb->stack_a->count; i++)
        printf ("| %d |", nb->stack_a->tab[i]);
		printf("\n");
}

void	ft_rb(t_data *nb)
{
	int	i;
	int	temp;

	i = 1;
	temp = nb->stack_b->tab[0];
	while (i++ < nb->stack_b->count)
		nb->stack_b->tab[i - 1] = nb->stack_b->tab[i];
	nb->stack_b->tab[i - 1] = temp;
	printf("rb\n");
	nb->moves++;
	for (int i = 0; i < nb->stack_a->count; i++)
        printf ("| %d |", nb->stack_a->tab[i]);
		printf("\n");
}

void	ft_rr(t_data *nb)
{
	int	i;
	int	tempa;
	int	tempb;

	i = 0;
	tempa = nb->stack_a->tab[0];
	tempb = nb->stack_b->tab[0];
	while (i < nb->tot)
	{
		nb->stack_a->tab[i] = nb->stack_a->tab[i + 1];
		nb->stack_b->tab[i] = nb->stack_b->tab[i + 1];
		i++;
	}
	nb->stack_a->tab[i] = tempa;
	nb->stack_b->tab[i] = tempb;
	printf("rr\n");
	nb->moves++;
	for (int i = 0; i < nb->stack_a->count; i++)
        printf ("| %d |", nb->stack_a->tab[i]);
		printf("\n");
	printf(" -----> ");
	for (int i = 0; i < nb->stack_b->count; i++)
        printf ("| %d |", nb->stack_b->tab[i]);
		printf("\n");
}