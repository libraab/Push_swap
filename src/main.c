/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:12:30 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/26 15:57:36 by abouhlel         ###   ########.fr       */
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
	int		i;
	t_ll	*list;
	t_data	*nb;

	i = 0;
	list = malloc(sizeof (t_ll));
	nb = malloc(sizeof (t_data));
	if (argc < 2)
		return (ft_error(0));
	if (argc == 2)
	{
		if (ft_valid_nbrs(argv[1]) == false)
			return (ft_error(1));
		ft_parsing(nb, argv[1]);
	}
	i = 1;
	if (argc > 2) 
	{
		while (argv[i])
		{
			if (ft_valid_nbrs2(argv[i]) == false)
				return (ft_error(1));
			if (ft_check_limits2(argv[i]) == 0)
				return (ft_error(5));
			i++;
		}
		ft_parsing2(nb, argv, argc);
	}
}
