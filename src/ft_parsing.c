/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:30:26 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/21 15:46:14 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_parsing(t_data *nb, char *str)
{
	int	i;

	i = 0;
	nb->initial_tab = malloc(sizeof(int) * (nb->tot + 1));
	nb->set = ft_split(str, ' ');
	if (!ft_check_limits(nb, nb->tot, str, 0))
		return (ft_error());
	while (i < nb->tot)
	{
		nb->initial_tab[i] = ft_atoi(nb->set[i]);
		i++;
	}
	if (!ft_check_double(nb, nb->tot))
		return (ft_error());
	if (ft_check_ifsorted(nb, nb->tot))
		exit(EXIT_SUCCESS);
	return (1);
}

int	ft_parsing2(t_data *nb, char **str)
{
	int		i;

	i = 0;
	nb->initial_tab = malloc(sizeof(int) * nb->tot);
	while (str[i + 1])
	{
		nb->initial_tab[i] = ft_atoi(str[i + 1]);
		i++;
	}
	if (!ft_check_double(nb, nb->tot))
		return (ft_error());
	if (ft_check_ifsorted(nb, nb->tot))
		exit(EXIT_SUCCESS);
	return (1);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
