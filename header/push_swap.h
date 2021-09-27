/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:31:49 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/27 12:00:54 by abouhlel         ###   ########.fr       */
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

// typedef struct s_ll
// {
// 	int			nbr;
// 	struct s_ll	*next;
// }				t_ll;

typedef struct s_stack
{
	int		val_max;
	int		val_min;
	int		val_med;
	int		count;
	int		*tab;
	int		val;
	int		x;
	int		y;
}			t_stack;

typedef struct s_data
{
	int		*tab;
	char	**set;
	int		value;
	int		tot;
	t_stack	a;
	t_stack	b;
}			t_data;

int		ft_error(int x);
int		ft_parsing(t_data *nb, char *str);
int		ft_parsing2(t_data *nb, char **str, int x);
int		ft_arg_count(char *str, char sp);
int		ft_check_double(t_data *nb, int nb_count);
int		ft_check_ifsorted(t_data *nb, int nb_count);
int		ft_check_limits(t_data *nb, int tab_len);
int		ft_check_limits2(char *str);
bool	ft_valid_nbrs(char *str);
bool	ft_valid_nbrs2(char *str);
void    ft_solve(t_data *nb);
void	ft_init_stack(t_stack *x, t_data *nb);

#endif