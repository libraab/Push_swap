/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:18:39 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/26 18:23:00 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void    ft_init_stack(t_stack *x, t_data *nb)
{
    x->val_max = nb->tab[0];
	x->val_min = nb->tab[0];
	x->val_med = nb->tab[nb->tot / 2];
    printf("median is -----> %d\n", nb->tab[nb->tot / 2]);
}

void    ft_solve(t_data *nb)
{
    int i;
    t_stack *a;

    i = 0;
    a = malloc(sizeof(t_stack));
    ft_init_stack(a, nb);
    if (nb->tot < 5)
    {
        while (i < nb->tot)
        {
            if (nb->tab[i] > a->val_max)
                a->val_max = nb->tab[i];
            if (nb->tab[i] < a->val_min)
                a->val_min = nb->tab[i];
            i++;
        }
        printf ("maximus is -----> %d\n", a->val_max);
        printf ("minimus is -----> %d\n", a->val_min);
    }
}

