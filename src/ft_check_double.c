/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:27:46 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/21 17:55:07 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int ft_check_double(t_data *nb, int nb_count)
{
    int i;
    int j;
    
    i = 0;
    while (i < nb_count)
    {
        j = i + 1;
        while (nb->tab[j])
        {
            if (nb->tab[i] == nb->tab[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int	ft_check_ifsorted(t_data *nb, int nb_count)
{
	int i;

    i = 0;
    static int x;
    x = nb->tab[i];
    while ((i + 1) < nb_count)
    {
        if (nb->tab[i + 1] > x)
            x = nb->tab[i + 1];
        else
            return (1);
        i++;
    }
    return (0);
}

int ft_check_limits(t_data *nb, int tab_len)
{
    int i;
    
    i = 0;
    while (i < tab_len)
    {
        if (ft_atoi2(nb->set[i]) > MAX || ft_atoi2(nb->set[i]) < MIN)
            return(0);
        i++;
    }
    return (1);
}