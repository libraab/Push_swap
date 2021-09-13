/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:12:30 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/13 18:58:11 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int main(int argc, char **argv)
{
    int i;
    int j;
    
    i = 0;
    if (argc < 2)
        return(ft_error(0));
    if (argc == 2)
    {
        
        while(argv[1][i] != 0)
        {

            if (!ft_isdigit(argv[1][i]) && argv[1][i] != ' ')
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
            j = 0;
            while (argv[i][j])
            {
                if (!ft_isdigit(argv[i][j]))
                    return(ft_error(1));
                j++;
            }
            
            i++;
        }
        ft_parsing2(argv, argc);
    }
    
}