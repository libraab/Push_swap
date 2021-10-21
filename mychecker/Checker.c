/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:17:49 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/21 15:17:33 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_sort(t_data *nb, int i)
{
	if (ft_strncmp(nb->action[i], "pa", 2) == 0)
		ft_pa(nb);
	else if (ft_strncmp(nb->action[i], "pb", 2) == 0)
		ft_pb(nb);
	else if (ft_strncmp(nb->action[i], "sa", 2) == 0)
		ft_sa(nb);
	else if (ft_strncmp(nb->action[i], "sb", 2) == 0)
		ft_sb(nb);
	else if (ft_strncmp(nb->action[i], "ra", 2) == 0)
		ft_ra(nb);
	else if (ft_strncmp(nb->action[i], "rb", 2) == 0)
		ft_rb(nb);
	else if (ft_strncmp(nb->action[i], "rrr", 3) == 0)
		ft_rrr(nb);
	else if (ft_strncmp(nb->action[i], "rra", 3) == 0)
		ft_rra(nb);
	else if (ft_strncmp(nb->action[i], "rrb", 3) == 0)
		ft_rrb(nb);
	else if (ft_strncmp(nb->action[i], "rr", 2) == 0)
		ft_rr(nb);
	else
		return (0);
	return (1);
}

void	ft_free_mychecker(t_data *nb)
{
	int	i;

	i = 0;
	free (nb->stack_a);
	free (nb->stack_b);
	if (nb->action != NULL)
	{
		while (nb->action[i])
		{
			free(nb->action[i]);
			i++;
		}
		free(nb->action);
	}
	i = 0;
	if (nb->set != NULL)
	{
		while (nb->set[i])
		{
			free(nb->set[i]);
			i++;
		}
		free(nb->set);
	}
	free (nb);
}

int	ft_get_output(t_data *nb, int i)
{
	int		count;
	char	*line;

	i = 0;
	line = NULL;
	nb->action = calloc(sizeof (char *), 6000);
	while (get_next_line(0, &line) > 0)
	{
		nb->action[i] = ft_strdup(line);
		free (line);
		i++;
	}
	free (line);
	count = i;
	i = 0;
	while (i < count)
	{
		if (!ft_sort(nb, i))
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*nb;

	nb = malloc(sizeof (t_data));
	if (argc < 2)
		return (EXIT_SUCCESS);
	if (argc == 2)
		ft_str_arg(nb, argv[1]);
	if (argc > 2)
	{
		nb->tot = argc - 1;
		ft_many_arg(nb, argv);
	}
	nb->stack_a = malloc(sizeof(t_stack));
	nb->stack_b = malloc(sizeof(t_stack));
	ft_transfert(nb);
	ft_get_output(nb, 0);
	if (ft_all_sorted(nb) == 1)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free (nb->stack_a->tab);
	free (nb->stack_b->tab);
	free (nb->initial_tab);
	ft_free_mychecker(nb);
	return (0);
}
