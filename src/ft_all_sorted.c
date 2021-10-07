/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:51:45 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/07 10:43:42 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int ft_all_sorted(t_data *nb)
{
    int i;

    i = 0;
    while (i + 1 < nb->tot)
    {
        if (nb->stack_a->tab[i] < nb->stack_a->tab[i + 1])//equal in case of 
        {
            //printf ("%d is inferior to %d\n", nb->stack_a->tab[i], nb->stack_a->tab[i + 1]);
            i++;
        }
        else
        {
            //printf ("%d is superior to %d\n", nb->stack_a->tab[i], nb->stack_a->tab[i + 1]);
            return (0);
        }
    }
    return (1);
}
