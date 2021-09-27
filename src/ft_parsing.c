/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:30:26 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/26 17:09:07 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_parsing(t_data *nb, char *str)
{
	int		i;
	int		tab_len;

	i = 0;
	tab_len = ft_arg_count(str, ' ');
	if (tab_len == 1)
		return (ft_error(3));
	nb->tab = malloc(sizeof(int) * tab_len + 1);
	nb->set = ft_split(str, ' ');
	if (!ft_check_limits(nb, tab_len))
		return (ft_error(5));
	while (i < tab_len)
	{
			nb->tab[i] = ft_atoi(nb->set[i]);
			i++;
	}
	nb->tab[i] = '\0';
	if (!ft_check_double(nb, tab_len))
		return (ft_error(2));
	if (!ft_check_ifsorted(nb, tab_len))
		return (ft_error(4));
	return (1);
}

int	ft_parsing2(t_data *nb, char **str, int ac)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	nb->tot = ac - 1;
	nb->tab = malloc(sizeof(int) * ac);
	while (str[i + 1])
	{
		nb->tab[i] = ft_atoi(str[i + 1]);
		i++;
	}
	if (!ft_check_double(nb, nb->tot))
		return (ft_error(2));
	if (!ft_check_ifsorted(nb, nb->tot))
		return (ft_error(4));
	return (1);
}
