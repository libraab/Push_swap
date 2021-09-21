/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:12:30 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/21 18:50:56 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

bool    ft_is_valid(char *str)
{
    int i;

    i = 0;
    if (ft_strlen(str) == 1 && ft_isdigit(str[0]) == false)
        return (false);
    if ((str[i] != '-' && str[i] != '+') && ft_isdigit(str[i]) == false)
        return(false);
    i++;
    while (str[i])
    {
        if (ft_isdigit(str[i]) == false)
           return (false);
        i++;
    }
    return (true);
}

int main(int argc, char **argv)
{
    int i;
    
    i = 0;
    if (argc < 2)
        return(ft_error(0));
    if (argc == 2)
    {
        
        while(argv[1][i] != 0)
        {
            if (!ft_isdigit(argv[1][i]) && ((argv[1][i] == '-' || argv[1][i] == '+') && argv[1][i - 1] != ' '))
                return(ft_error(1));
            i++;
        }
        ft_parsing(argv[1]);
    }
    i = 1;
    if (argc > 2)
    {
        while(argv[i])
        {
            // printf("%s\n", ft_is_valid(argv[i]) ? "true" : "false");
            if (ft_is_valid(argv[i]) == false)
                return(ft_error(1));
            i++;
        }
        ft_parsing2(argv, argc);
    }
    
}