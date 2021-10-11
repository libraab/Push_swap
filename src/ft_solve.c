/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:18:39 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/11 15:51:36 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_transfert(t_data *nb)
{
	int	i;

	i = 0;
	//=================================================
	nb->stack_a->tab = malloc (sizeof (int) * nb->tot);
	nb->stack_b->tab = malloc (sizeof (int) * nb->tot);
	//=================================================
	while (i < nb->tot)
	{
		nb->stack_a->tab[i] = nb->initial_tab[i];
		i++;
	}
}

int	ft_solve_2(t_data *nb)
{
	ft_sa(nb);
	return (1);
}

void	ft_solve_all(t_data *nb)
{
	int	i;

	i = 0;
	nb->moves = 0;
	//====================================
	nb->stack_a = malloc(sizeof(t_stack));
	nb->stack_b = malloc(sizeof(t_stack));
	//====================================
	nb->stack_a->count = nb->tot;
	nb->stack_b->count = 0;
	ft_transfert(nb);
	if (nb->tot == 2)
		ft_solve_2(nb);
	if (nb->tot == 3)
		ft_solve_3a(nb);
	if (nb->tot > 3)
	{
		while (!ft_all_sorted(nb))
			ft_solve_more2(nb);
	}
		
	//}
	//********************************************
	//printing
	// while (i < nb->tot)
	// 	printf("| %d ", nb->stack_a->tab[i++]);
	// 	printf("\n");
	//*********************************************
	//---------------------------------------------------------------
	//nb->stack_b = malloc(sizeof(t_stack)); //not necessary for now
	// printf("taille du tableau %lu\n", (sizeof(int) * 10));
	// printf("taille du pointeur de nb->tab %lu\n", sizeof(int *));
	// printf("taille de la structure %lu\n", sizeof(t_data));
	//ft_init_stack(nb->stack_b, nb); //uncomment if used
	//---------------------------------------------------------------
}
