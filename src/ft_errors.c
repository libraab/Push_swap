/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:50:56 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/21 11:30:24 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_all_sorted(t_data *nb)
{
	int	i;

	i = 0;
	while (i + 1 < nb->tot)
	{
		if (nb->stack_a->tab[i] > nb->stack_a->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	free_car_je_leaks(t_data *nb)
{
	int	i;

	i = 0;
	free(nb->stack_a->tab);
	free(nb->stack_b->tab);
	free(nb->stack_a);
	free(nb->stack_b);
	free(nb->initial_tab);
	if (nb->set != NULL)
	{
		while (nb->set[i])
		{
			free(nb->set[i]);
			i++;
		}
		free(nb->set);
	}
	free(nb);
}

void	init_list(t_data *nb)
{
	nb->initial_tab = NULL;
	nb->set = NULL;
	nb->stack_a = NULL;
	nb->stack_b = NULL;
}
