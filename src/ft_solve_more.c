/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:53:21 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/12 18:35:37 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int ft_search_median(t_data *nb, int x)
{
    int i;
    int under;
    int nbr;
    int j;
    int above;

    
    i = 0;
    j = 0;
    if (x ==0)
    {
        while (i < nb->stack_a->count)
        {
            nbr = nb->stack_a->tab[i];
            above = 0;
            under = 0;
            j = 0;
            while (j < nb->stack_a->count)
            {
                if (nb->stack_a->tab[j] > nbr)
                    above++;
                if (nb->stack_a->tab[j] < nbr)
                    under++;
                j++;
            }
            if (nb->stack_a->count % 2 == 0)
            {
                if (above == under + 1)
                    return (nbr);
            }
            else
            {
                if (above == under)
                    return (nbr);
            }
            i++;
        }
        return (nb->stack_a->tab[nb->stack_a->count / 2]);
    }
    if (x == 1)
    {
        while (i < nb->stack_b->count)
        {
            nbr = nb->stack_b->tab[i];
            above = 0;
            under = 0;
            j = 0;
            while (j < nb->stack_b->count)
            {
                if (nb->stack_b->tab[j] > nbr)
                    above++;
                if (nb->stack_b->tab[j] < nbr)
                    under++;
                j++;
            }
            if (nb->stack_b->count % 2 == 0)
            {
                if (above == under + 1)
                    return (nbr);
            }
            else
            {
                if (above == under)
                    return (nbr);
            }
            i++;
        }
        return (nb->stack_b->tab[nb->stack_b->count / 2]);
    }
    return (0);
}

int    ft_swap_top(t_data *nb)
{
    if ((nb->stack_a->tab[0] > nb->stack_a->tab[1]) && (nb->stack_b->tab[1] > nb->stack_b->tab[0]))
        ft_ss(nb);
    if (nb->stack_a->tab[0] > nb->stack_a->tab[1])
        ft_sa(nb);
    if (nb->stack_b->tab[0] < nb->stack_b->tab[1])
        ft_sb(nb);
    return (1);
}

bool    number_under_exist(t_data *nb)
{
    int i;
    bool t;

    i = 0;
    t = false;
    while (i < nb->stack_a->count)
    {
        if (nb->stack_a->tab[i] < nb->med)
            t = true;
        i++;
    }
    return (t);
}

int	ft_solve_more2(t_data *nb)
{
    while (nb->stack_a->count > 3)
    {
        nb->med = ft_search_median(nb, 0);
    
        while (number_under_exist(nb) == true && nb->stack_a->count > 3 )
        {   
            if (nb->stack_b->count > 1)
                ft_swap_top(nb);
            if (nb->stack_a->tab[0] > nb->med)
                ft_ra(nb);
            if (nb->stack_a->tab[0] < nb->med)
                ft_pb(nb);
            if (nb->stack_a->tab[0] == nb->med)
                ft_ra(nb);
        }
    }
    if (nb->stack_a->count == 3)
        ft_solve_3a(nb);
    
    // printf("stack a----->");
    // for (int y = 0; y < nb->stack_a->count ;y++)
    //     printf("[%d]", nb->stack_a->tab[y]);
    // printf("\nstack b----->");
    // for (int y = 0; y < nb->stack_b->count ;y++)
    //     printf("[%d]", nb->stack_b->tab[y]);
    // printf ("\n");
    
    while (nb->stack_b->count > 0 && (!ft_all_sorted(nb)))
    {
        nb->med = ft_search_median(nb, 1);
       
                ft_pa(nb);
                ft_swap_top(nb);
            
          
        
        // if (nb->stack_b->count == 3)
        //     ft_solve_3b(nb);
        if (ft_stack_sorted(nb, nb->stack_b->count, 1) == 1)
        {
            while (nb->stack_b->count > 0)
                ft_pa(nb);
        }
    }
    
    
    // printf("stack a----->");
    // for (int y = 0; y < nb->stack_a->count ;y++)
    //     printf("[%d]", nb->stack_a->tab[y]);
    // printf("\nstack b----->");
    // for (int y = 0; y < nb->stack_b->count ;y++)
    //     printf("[%d]", nb->stack_b->tab[y]);

    
    //exit(1);

    return (1);
    
}

// int	ft_solve_more2(t_data *nb)
// {
//     int i;

//     while (!ft_all_sorted(nb))
//     {
//         i = 0;
//         while (nb->stack_a->tab[0] != ft_search_min(nb, 0) && (ft_stack_sorted(nb, nb->stack_a->count, 0) == 0)) //&& nb->stack_a->tab[0] != ft_search_min2(nb, 0)) && (ft_stack_sorted(nb, nb->stack_a->count, 0) == 0))
//         {
//             if (nb->stack_a->tab[i] == ft_search_min(nb, 0))
//             {
//                 if (i <= (nb->stack_a->count / 2))
//                 {
//                     while (nb->stack_a->tab[0] != ft_search_min(nb, 0))
//                         ft_ra(nb);
//                 }
//                 else
//                 {
//                     while (nb->stack_a->tab[0] != ft_search_min(nb, 0))
//                         ft_rra(nb);
//                 }
//             }
//             if (nb->stack_a->tab[i] == ft_search_min2(nb, 0))
//             {
//                 if (i <= (nb->stack_a->count / 2))
//                 {
//                     while (nb->stack_a->tab[0] != ft_search_min2(nb, 0))
//                         ft_ra(nb);
//                 }
//                 else
//                 {
//                     while (nb->stack_a->tab[0] != ft_search_min2(nb, 0))
//                         ft_rra(nb);
//                 }
//             }
//             i++;
//         }
//         while ((nb->stack_a->count > 3) && (ft_stack_sorted(nb, nb->stack_a->count, 0) == 0))
//         {
//             if (nb->stack_a->tab[0] == ft_search_min(nb, 0))
//             {
//                 ft_pb(nb);
//                 ft_solve_more2(nb);
//             }
//         }
//         if (nb->stack_a->count == 3)
//             ft_solve_3(nb);
//         while (nb->stack_b->count > 0)
//         {
//             ft_pa(nb);
//             if (nb->stack_a->tab[0] > nb->stack_a->tab[1])
//             {
//                 if (nb->stack_a->tab[0] > nb->stack_a->tab[nb->stack_a->count - 1])
//                     ft_ra(nb);
//                 else
//                     ft_sa(nb);
//             }
//         }
//     }
    
//     return (1);
// }
    