/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:12:30 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/28 16:56:49 by abouhlel         ###   ########.fr       */
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
	t_data	*nb;

	i = 0;
	nb = malloc(sizeof (t_data));
	if (argc < 2)
		return (ft_error());
	if (argc == 2)
	{
		if (ft_valid_nbrs(argv[1]) == false)
			return (ft_error());
		ft_parsing(nb, argv[1]);

		//printing
		for (int i = 0; i < ft_arg_count(argv[1], ' '); i++)
			printf("%d\n", nb->tab[i]);
	}
	i = 1;
	if (argc > 2) 
	{
		while (argv[i])
		{
			if (ft_valid_nbrs2(argv[i]) == false)
				return (ft_error());
			if (ft_check_limits2(argv[i]) == 0)
				return (ft_error());
			i++;
		}
		ft_parsing2(nb, argv, argc);
		
		i = 0;//            printing
		while (nb->tot--)
			printf("%d\n", nb->tab[i++]);
		
	}
}
