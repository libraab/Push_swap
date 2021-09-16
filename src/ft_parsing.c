/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:30:26 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/16 14:26:41 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_arg_count(char *str, char sp)
{
	int		i;
	int		nb_count;

	nb_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != sp && (str[i + 1] == sp || str[i + 1] == '\0'))
			nb_count++;
		i++;
	}
	return (nb_count);
}

int ft_parsing(char *str)
{
	int		i;
	int		tab_len;
	t_data	*nb;

	i = 0;
	nb = malloc(sizeof (t_data));
	tab_len = ft_arg_count(str, ' ');
	nb->tab = malloc(sizeof(int) * tab_len + 1);
	nb->set = ft_split(str, ' ');
	while (i < tab_len)
	{
		nb->tab[i] = ft_atoi(nb->set[i]);
		i++;
	}
	nb->tab[i] = '\0';
	ft_check_double()
	// printf("total numbers %d\n", tab_len);
	// for (int i = 0; i < tab_len; i++)
	// 	printf("the nb are %d\n", nb->tab[i]);
	return (1);
}

int ft_parsing2(char **str, int ac)
{
	int		i;
	int		j;
	t_data	*nb;

	i = 0;
	j = 0;
	nb = malloc(sizeof (t_data));//<--------search this (Tom's way to secure the struct)
	nb->tab = malloc(sizeof(int) * ac);
	while (str[i + 1])
	{
		nb->tab[i] = ft_atoi(str[i + 1]);
		i++;
	}
	nb->tot = ac - 1;
	// for (int i = 0; i < nb->tot; i++)
	// 	printf("the numbers are %d\n", nb->tab[i]);
	// printf("total nb %d\n", nb->tot);
	return (1);
}