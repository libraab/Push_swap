/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:27:46 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/24 19:44:44 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

bool	ft_valid_nbrs(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 1 && ft_isdigit(str[0]) == false)
		return (false);
	if ((str[i] != '-' && str[i] != '+') && ft_isdigit(str[i]) == false)
		return (false);
	i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_valid_nbrs2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == false && (str[i] == '-' || str[i] == '+')
			&& (str[i - 1] != ' ' || ft_isdigit(str[i + 1]) == false))
			return (false);
		i++;
	}
	return (true);
}

int	ft_check_double(t_data *nb, int nb_count)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb_count)
	{
		j = i + 1;
		while (j < nb_count)
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
	int			i;
	static int	x;

	i = 0;
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

int	ft_check_limits(t_data *nb, int tab_len)
{
	int	i;

	i = 0;
	while (i < tab_len)
	{
		printf("in\n");
		if (ft_atoi2(nb->set[i]) > MAX || ft_atoi2(nb->set[i]) < MIN)
			return (0);
		i++;
	}
	return (1);
}
