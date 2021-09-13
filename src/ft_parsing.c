/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:30:26 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/13 19:00:40 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int ft_parsing(char *str)
{
	int		i;
	int		j;
	int		len;
	t_data	nb;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	nb.tab = malloc(sizeof(int) * len + 1);// len is not the right amount, it's tooooo much
	nb.set = ft_split(str, ' ');
	while (nb.set[i] != '\0')
	{
		nb.tab[i] = ft_atoi(nb.set[i]);
		i++;
	}
	for (int i = 0; nb.tab[i] != '\0'; i++)
		printf("the numbers are %d\n", nb.tab[i]);
		printf("%d\n", i);
	return (1);
}

int ft_parsing2(char **str, int x)
{
	int		i;
	int		j;
	t_data	*nb;

	i = 0;
	j = 0;
	nb = malloc(sizeof (t_data));//<--------
	nb->tab = malloc(sizeof(int) * x);
	while (str[i + 1])
	{
		nb->tab[i] = ft_atoi(str[i + 1]);
		i++;
	}
	nb->tot = x - 1;
	for (int i = 0; i < nb->tot; i++)
		printf("the numbers are %d\n", nb->tab[i]);
	return (1);
}