/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:34:04 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/12/03 12:19:53 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <ft_printf.h>
# include <get_next_line.h>
# include <libft_stuff.h>
# include <limits.h>
# include <stdlib.h>
# define INVALID_LIST 1
# define MALLOC_LIST_ERROR 2
# define NO_ERROR 0
# define VALID_LIST 0
# define NO_INPUT 0
# ifndef LOW_CHUNK
#  define LOW_CHUNK 2
# endif
# ifndef BIG_CHUNK
#  define BIG_CHUNK 4
# endif
# define WRONG_INPUT -1

typedef struct s_stack
{
	int				value;
	int				isvalid;
	struct s_stack	*next;
}					t_stack;

typedef struct s_tree
{
	int				value;
	struct s_tree	*right;
	struct s_tree	*left;
}					t_tree;

typedef struct s_score
{
	int				actual_pos;
	int				good_pos;
	int				total_actions;
}					t_score;
/*aff_functions.c*/
void				px(t_stack **stack_a, t_stack **stack_b, char x,
						int to_print);
void				rx(t_stack **stack_a, t_stack **stack_b, char x,
						int to_print);
void				rrx(t_stack **stack_a, t_stack **stack_b, char x,
						int to_print);
void				sx(t_stack **stack_a, t_stack **stack_b, char x,
						int to_print);
/*chunk_stuff.c*/
void				ps_chunk_cutter(t_stack **stack_c, t_stack **stack_d,
						int chunk_count);
void				ps_push_chunk(t_stack **stack_a, t_stack **stack_b,
						int max_value);
int					ps_find_chunk(t_stack **stack_a, int reverse,
						int max_value);
void				ps_transfer_chunks(t_stack **stack_a, t_stack **stack_b,
						t_stack **stack_c, t_stack **stack_d);
/*list_utils.c*/
int					ps_destroy_list(t_stack **first, int error);
int					ps_addback(t_stack **first, int value);
int					ps_addfront(t_stack **first, int value);
int					ps_get_stack_len(t_stack **first);
int					ps_stack_cmp(t_stack **stack_a, t_stack **stack_b);
/*list_utils2.c*/
int					ps_val_is_min(t_stack **first, int value);
int					ps_val_is_max(t_stack **first, int value);
t_stack				*ps_sort_stack(t_stack *stack_top);
void				ps_destroy_stacks(t_stack **stack_a, t_stack **stack_b,
						t_stack **stack_c, t_stack **stack_d);
/*parsing.c*/
int					ps_parse_entries(int ac, char **av, t_stack **stack_a);
int					ps_parse_mult_args(int ac, char **av, t_stack **stack_a);
int					ps_parse_one_arg(t_stack **stack_a, char *av);
int					ps_valid_stack(t_stack **stack_a);
int					ps_valid_list(int ac, char **av, int isnt_split);
/*parsing2.c*/
int					ps_error_handler(int error);
int					ps_check_len_digits(int ac, char **av, int isnt_split);
/*solver_three.c*/
void				ps_solve_three(t_stack **stack_a);
void				ps_actions_three(t_stack **stack_a, t_stack *first,
						t_stack *second, t_stack *third);
void				ps_solve_two(t_stack **stack_a);
/*stack_actions.c*/
void				ps_push_a_to_b(t_stack **stack_a, t_stack **stack_b);
void				ps_push(t_stack **first, t_stack *to_push);
void				ps_pop(t_stack **first);
void				ps_roll_reverse(t_stack **first);
/*stack_actions2.c*/
void				ps_roll(t_stack **first);
void				ps_swap(t_stack **first);
/*tree_utils.c*/
int					ps_add_to_tree(t_tree *tree_top, int value);
int					ps_decomp_tree(t_tree *tree_top, t_stack **sorted_list);
t_stack				*ps_tree_burner(t_tree *tree_top);
/*ps_main.c*/

/*solver.c*/
int					ps_solve(t_stack **stack_a, t_stack **stack_b);
void				ps_final_roll(t_stack **stack_a, t_stack **stack_c);
/*solver_utils*/
void				ps_flush_b(t_stack **stack_a, t_stack **stack_b);
t_score				ps_get_score_flush_b(t_stack **stack_a, t_stack **stack_b,
						int position);
int					ps_get_good_pos(t_stack **stack_a, t_stack **stack_b,
						int position);
void				ps_push_good_pos(t_stack **stack_a, t_stack **stack_b,
						t_score best);
t_score				ps_process_output(t_stack **stack_a, t_stack **stack_b,
						t_score output);
/*solver_utils2.c*/
int					ps_get_minmax_pos(t_stack **stack_a);
int					ps_get_intermediate_pos(t_stack **stack_a, int value);
void				ps_roll_same_side(t_stack **stack_a, t_stack **stack_b,
						t_score *best);
void				ps_roll_both_side(t_stack **stack_a, t_stack **stack_b,
						t_score *best);

/********************************/
/*************CHECKER************/
/********************************/
int					ps_process_inputs(t_stack **stack_a, t_stack **stack_b,
						t_stack **stack_c, int verbose);
void				ps_checker(int ac, char **av, t_stack **stack_a,
						int verbose);
void				ps_compare_stacks(t_stack **stack_a, t_stack **stack_c);
int					ps_process_line(t_stack **stack_a, t_stack **stack_b,
						char *line, int verbose);
/*aff_stack.c*/
void				ps_aff_stacks(t_stack **stack_a, t_stack **stack_b,
						char first_char, char second_char);

void				ps_print_stack(t_stack **stack_a, char first_char);

#endif