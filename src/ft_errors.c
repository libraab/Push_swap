/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:50:56 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/27 13:43:19 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_error(int x)
{
	if (x == 0)
		write(2, "Error!\nThere is no argument\n", 28);
	if (x == 1)
		write(2, "Error!\nArguments must be digits\n", 31);
	if (x == 2)
		write(2, "Error!\nThere is a duplicated number\n", 36);
	if (x == 3)
		write(2, "Error!\nThere is only one argument\n", 34);
	if (x == 4)
		write(2, "Error!\nNumbers are already sorted\n", 34);
	if (x == 5)
		write(2, "Error!\nYou exceeded the limits\n", 31);
	exit(EXIT_FAILURE);
}
