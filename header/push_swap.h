/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:31:49 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/26 14:52:45 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../header/push_swap.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>

# define MAX 2147483647
# define MIN -2147483648

typedef struct s_ll
{
	int			nbr;
	struct s_ll	*next;
}				t_ll;

typedef struct s_stack
{
	t_ll	*first;
	int		val_max;
	int		val_min;
	int		val_med;
	int		count;
	int		val;
}			t_stack;

typedef struct s_data
{
	int		*tab;
	char	**set;
	int		value;
	t_stack	*a;
	t_stack	*b;
	int		x;
	int		y;
	int		tot;
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

#endif