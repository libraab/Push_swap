/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:04:02 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/19 17:04:19 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/push_swap.h"

int	ft_solve_2(t_data *nb)
{
	ft_sa(nb);
	return (1);
}

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

int	ft_str_arg(t_data *nb, char *argv)
{
	int	i;

	i = 0;
	nb->tot = ft_arg_count(argv, ' ');
	if (ft_valid_nbrs(argv) == false)
		return (ft_error());
	ft_parsing(nb, argv);
	return (1);
}

int	ft_many_arg(t_data *nb, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_valid_nbrs2(argv[i]) == false)
			return (ft_error());
		if (ft_check_limits(nb, 42, argv[i], 1) == 0)
			return (ft_error());
		i++;
	}
	ft_parsing2(nb, argv);
	return (1);
}
