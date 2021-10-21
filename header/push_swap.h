/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:31:49 by abouhlel          #+#    #+#             */
/*   Updated: 2021/10/21 15:39:26 by abouhlel         ###   ########.fr       */
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
	char	**action;
	char	**set;
	int		med;
	int		moves;
	int		tot;
}			t_data;

/////// * A C T I O N S * /////////////

void	ft_pa(t_data *nb);
void	ft_pb(t_data *nb);
void	ft_sa(t_data *nb);
void	ft_sb(t_data *nb);
void	ft_ss(t_data *nb);
void	ft_ra(t_data *nb);
void	ft_rb(t_data *nb);
void	ft_rr(t_data *nb);
void	ft_rra(t_data *nb);
void	ft_rrb(t_data *nb);
void	ft_rrr(t_data *nb);

////// * M E E T I N G * ////////////////////////

int		ft_topbot(t_data *nb, int nbr);
void	ft_top_top(t_data *nb, int nbr);
void	ft_bot_bot(t_data *nb, int nbr);
void	ft_bot_top(t_data *nb, int nbr);
void	ft_top_bot(t_data *nb, int nbr);

///////// * P A R S I N G * ///////////////////////

int		ft_parsing(t_data *nb, char *str);
int		ft_parsing2(t_data *nb, char **str);
int		ft_error(void);
int		ft_all_sorted(t_data *nb);
void	ft_transfert(t_data *nb);
void	ft_solve(t_data *nb);
int		ft_solve_2(t_data *nb);
int		ft_solve_3(t_data *nb);
int		ft_check_limits(t_data *nb, int tab_len, char *str, int x);
int		ft_check_double(t_data *nb, int nb_count);
int		ft_check_ifsorted(t_data *nb, int nb_count);
bool	ft_valid_nbrs(char *str);
bool	ft_valid_nbrs2(char *str);
int		ft_many_arg(t_data *nb, char **argv);
int		ft_str_arg(t_data *nb, char *argv);
int		ft_arg_count(char *str, char sp);

//////// * T H E _ C O R E * ///////////////////////////

int		ft_search_next_a(t_data *nb, int nbr);
int		ft_search_next_b(t_data *nb, int nbr);
int		ft_real_index_a(t_data *nb, int nbr);
int		ft_real_index_b(t_data *nb, int nbr);
int		ft_index_a(t_data *nb, int nbr);
int		ft_index_b(t_data *nb, int nbr);
int		ft_best_option_a(t_data *nb);
int		ft_best_option_b(t_data *nb);
int		ft_search_max(t_data *nb);
int		ft_search_min(t_data *nb);
int		ft_push_a(t_data *nb);
int		ft_swing(t_data *nb);
int		ft_big_algo(t_data *nb);
void	free_car_je_leaks(t_data *nb);
void	init_list(t_data *nb);

//////// * C H E C K E R  _ F C T * /////////////////

void	ft_free_mychecker(t_data *nb);
int		ft_sort(t_data *nb, int i);
int		ft_get_output(t_data *nb, int i);

#endif