/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:50:56 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/19 16:45:33 by abouhlel         ###   ########.fr       */
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
