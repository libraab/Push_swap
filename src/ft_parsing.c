/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:30:26 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/24 12:07:02 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_parsing(char *str)
{
	int		i;
	int		tab_len;
	t_data	*nb;

	i = 0;
	nb = malloc(sizeof (t_data));
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
	for (int i = 0; i < tab_len; i++)
		printf("%d\n", nb->tab[i]);
	return (1);
}

int	ft_parsing2(char **str, int ac)
{
	int		i;
	int		j;
	t_data	*nb;

	i = 0;
	j = 0;
	nb = malloc(sizeof (t_data));
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
	while (nb->tot--)
		printf("%d\n", nb->tab[j++]);
	return (1);
}
