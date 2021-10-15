/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:38:17 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/15 17:00:06 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void    ft_reset(t_data *nb)
{
    int	i;

	i = 0;
	nb->stack_a->count = nb->tot;
	nb->stack_b->count = 0;
	nb->moves = 0;
	while (i < nb->tot)
	{
		nb->stack_a->tab[i] = nb->initial_tab[i];
		i++;
	}
}