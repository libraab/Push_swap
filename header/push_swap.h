/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:31:49 by abouhlel          #+#    #+#             */
/*   Updated: 2021/09/22 15:03:46 by abouhlel         ###   ########.fr       */
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

typedef struct s_data
{
	int		*tab;
	char	**set;
	int		value;
	int		x;
	int		y;
	int		tot;
}			t_data;

int		ft_error(int x);
int		ft_parsing(char *str);
int		ft_parsing2(char **str, int x);
int		ft_arg_count(char *str, char sp);
int		ft_check_double(t_data *nb, int nb_count);
int		ft_check_ifsorted(t_data *nb, int nb_count);
int		ft_check_limits(t_data *nb, int tab_len);
bool	ft_is_valid(char *str);
bool	ft_is_valid2(char *str);

#endif