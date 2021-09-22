/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:12:30 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/22 10:16:12 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

bool	ft_is_valid(char *str)
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

bool	ft_is_valid2(char *str)
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

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		return (ft_error(0));
	if (argc == 2)
	{
		if (ft_is_valid2(argv[1]) == false)
			return (ft_error(1));
		ft_parsing(argv[1]);
	}
	i = 1;
	if (argc > 2)
	{
		while (argv[i])
		{
			if (ft_is_valid(argv[i]) == false)
				return (ft_error(1));
			i++;
		}
		ft_parsing2(argv, argc);
	}
}
