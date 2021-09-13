/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:50:56 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/13 10:03:58 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int    ft_error(int x)
{
    if (x == 0)
        write(2, "Error!\nThere is no argument\n", 28);
    if (x == 1)
        write(2, "Error!\nArguments must be digits\n", 31);
    return(0);
}