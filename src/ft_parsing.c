/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:30:26 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/13 11:03:50 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int ft_parsing(char *str)
{
    int i;
    int len;
    t_data nb;

    i = 0;
    len = ft_strlen(str);
    while (str[i] != '\0')
    {
        if(str[i] == ' ')
        
        i++;
    }
    printf("%zu\n", ft_strlen(str));
    return (1);
}