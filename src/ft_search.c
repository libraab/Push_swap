/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:25:55 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/14 11:09:59 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_search_max(t_data *nb, int x)
{
	int	i;

	i = 0;
	if (x == 0)
	{
		nb->stack_a->max = nb->stack_a->tab[i];
		while (i < nb->stack_a->count)
		{
			if (nb->stack_a->tab[i] > nb->stack_a->max)
				nb->stack_a->max = nb->stack_a->tab[i];
			i++;
		}
		return (nb->stack_a->max);
	}
	if (x == 1)
	{
		nb->stack_b->max = nb->stack_b->tab[i];
		while (i < nb->stack_b->count)
		{
			if (nb->stack_b->tab[i] > nb->stack_b->max)
				nb->stack_b->max = nb->stack_b->tab[i];
			i++;
		}
		return (nb->stack_b->max);
	}
	return (1);
}

int	ft_search_min(t_data *nb, int x)
{
	int	i;

	i = 0;
	if (x == 0)
	{
		nb->stack_a->min = nb->stack_a->tab[i];
		while (i < nb->stack_a->count)
		{
			if (nb->stack_a->tab[i] < nb->stack_a->min)
				nb->stack_a->min = nb->stack_a->tab[i];
			i++;
		}
		return (nb->stack_a->min);
	}
	if (x == 1)
	{
		nb->stack_b->min = nb->stack_b->tab[i];
		while (i < nb->stack_b->count)
		{
			if (nb->stack_b->tab[i] < nb->stack_b->min)
				nb->stack_b->min = nb->stack_b->tab[i];
			i++;
		}
		return (nb->stack_b->min);
	}
	return (1);
}

int	ft_search_min2(t_data *nb, int x)
{
	int	i;

	i = 0;
	if (x == 0)
	{
		nb->stack_a->min2 = ft_search_max(nb, 0);
		while (i < nb->stack_a->count)
		{
			if ((nb->stack_a->tab[i] < nb->stack_a->min2)
				&& (nb->stack_a->tab[i] > nb->stack_a->min))
				nb->stack_a->min2 = nb->stack_a->tab[i];
			i++;
		}
		return (nb->stack_a->min2);
	}
	if (x == 1)
	{
		nb->stack_b->min2 = ft_search_max(nb, 1);
		while (i < nb->stack_b->count)
		{
			if ((nb->stack_b->tab[i] < nb->stack_b->min2)
				&& (nb->stack_b->tab[i] > nb->stack_b->min))
				nb->stack_b->min2 = nb->stack_b->tab[i];
			i++;
		}
		return (nb->stack_b->min2);
	}
	return (1);
}

int	ft_search_max2(t_data *nb, int x)
{
	int	i;

	i = 0;
	if (x == 0)
	{
		nb->stack_a->max2 = ft_search_min(nb, 0);
		while (i < nb->stack_a->count)
		{
			if ((nb->stack_a->tab[i] > nb->stack_a->max2)
				&& (nb->stack_a->tab[i] < nb->stack_a->max))
				nb->stack_a->max2 = nb->stack_a->tab[i];
			i++;
		}
		return (nb->stack_a->max2);
	}
	if (x == 1)
	{
		nb->stack_b->max2 = ft_search_min(nb, 1);
		while (i < nb->stack_b->count)
		{
			if ((nb->stack_b->tab[i] > nb->stack_b->max2)
				&& (nb->stack_b->tab[i] < nb->stack_b->max))
				nb->stack_b->max2 = nb->stack_b->tab[i];
			i++;
		}
		return (nb->stack_b->max2);
	}
	return (1);
}

int ft_search_median(t_data *nb, int x)
{
    int i;
    int under;
    int nbr;
    int j;
    int above;

    
    i = 0;
    j = 0;
    if (x ==0)
    {
        while (i < nb->stack_a->count)
        {
            nbr = nb->stack_a->tab[i];
            above = 0;
            under = 0;
            j = 0;
            while (j < nb->stack_a->count)
            {
                if (nb->stack_a->tab[j] > nbr)
                    above++;
                if (nb->stack_a->tab[j] < nbr)
                    under++;
                j++;
            }
            if (nb->stack_a->count % 2 == 0)
            {
                if (above == under + 1)
                    return (nbr);
            }
            else
            {
                if (above == under)
                    return (nbr);
            }
            i++;
        }
        return (nb->stack_a->tab[nb->stack_a->count / 2]);
    }
    if (x == 1)
    {
        while (i < nb->stack_b->count)
        {
            nbr = nb->stack_b->tab[i];
            above = 0;
            under = 0;
            j = 0;
            while (j < nb->stack_b->count)
            {
                if (nb->stack_b->tab[j] > nbr)
                    above++;
                if (nb->stack_b->tab[j] < nbr)
                    under++;
                j++;
            }
            if (nb->stack_b->count % 2 == 0)
            {
                if (above == under + 1)
                    return (nbr);
            }
            else
            {
                if (above == under)
                    return (nbr);
            }
            i++;
        }
        return (nb->stack_b->tab[nb->stack_b->count / 2]);
    }
    return (0);
}