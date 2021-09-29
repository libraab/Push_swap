/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:31:49 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/29 15:29:01 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../header/push_swap.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define MAX 2147483647
# define MIN -2147483648

typedef struct s_stack
{
	int		count;
	int		*tab;
	int		max;
	int		min;
}			t_stack;

typedef struct s_data
{
	int		*initial_tab;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		val_max;
	int		val_min;
	int		med;
	char	**set;
	int		value;
	int		tot;
}			t_data;

int		ft_error(void);
int		ft_parsing(t_data *nb, char *str);
int		ft_parsing2(t_data *nb, char **str);
int		ft_arg_count(char *str, char sp);
int		ft_check_double(t_data *nb, int nb_count);
int		ft_check_ifsorted(t_data *nb, int nb_count);
int		ft_check_limits(t_data *nb, int tab_len);
int		ft_check_limits2(char *str);
bool	ft_valid_nbrs(char *str);
bool	ft_valid_nbrs2(char *str);
int    ft_solve_3(t_data *nb);
int    ft_solve_2(t_data *nb);
void    ft_solve_all(t_data *nb);
int    ft_solve_more(t_data *nb);
void	ft_init_val(t_data *nb);
void    ft_pa(t_data *nb);
void    ft_pb(t_data *nb);
void    ft_sa(t_data *nb);
void    ft_sb(t_data *nb);
void    ft_ra(t_data *nb);
void    ft_rb(t_data *nb);
void    ft_rra(t_data *nb);
void    ft_rrb(t_data *nb);

#endif