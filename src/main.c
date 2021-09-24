/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:12:30 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/24 18:54:04 by abouhlel         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		return (ft_error(0));
	if (argc == 2)
	{
		if (ft_valid_nbrs(argv[1]) == false)
		{
			printf("%s\n", argv[1]);
			return (ft_error(1));
		}
		ft_parsing(argv[1]);
	}
	i = 1;
	if (argc > 2)
	{
		while (argv[i])
		{
			if (ft_valid_nbrs2(argv[i]) == false)
				return (ft_error(1));
			i++;
		}
		ft_parsing2(argv, argc);
	}
}
