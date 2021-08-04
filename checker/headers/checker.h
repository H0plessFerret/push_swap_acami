/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:01:26 by acami             #+#    #+#             */
/*   Updated: 2021/08/04 12:58:47 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <inttypes.h>
# include <unistd.h>
# include <limits.h>
# include "double_circular_list.h"
# include "get_next_line.h"
# include "utils.h"

typedef struct s_env			t_env;
typedef enum e_actionId			t_actionId;
typedef void					(*t_operation)(t_env *env);

struct s_env
{
	t_dCList	*a_head;
	t_dCList	*b_head;
	t_dCList	*actions;
	int64_t		a_size;
	int64_t		b_size;
};

enum e_actionId
{
	act_error = -1,
	act_nothing	= 0,
	act_sa,
	act_sb,
	act_ss,
	act_pa,
	act_pb,
	act_ra,
	act_rb,
	act_rr,
	act_rra,
	act_rrb,
	act_rrr
};

// Initialize environment variables
void	initEnv(t_env *env);

// Free lists and before exiting the program
void	clearEnv(t_env *env);

// Check input for validity and save it (if valid) to a DCList
void	parseInput(t_env *env, int32_t argc, const char **argv);

// Check if the array is properly sorted
bool	isSorted(t_dCList *head);

// Read actions from file descriptor fd
void	readActions(t_env *env, int32_t fd);

// Do actions from action list
void	doActions(t_env *env);

//---------------------------- Basic operations ----------------------------//

// Basic forwards rotation on 1 elem of a dCList
void	rotate(t_dCList **head);

// Basic backwards rotation on 1 elem of a dCList
void	revRotate(t_dCList **head);

// Basic swap of two top elems of a dCList
void	swap(t_dCList *head);

// Push the head element from one list to another, making it a head there
void	push(t_dCList **from_head, t_dCList **to_head);

// Adds a new entry to the action list
void	pushAction(t_dCList **head, t_actionId action);

//----------------------------- Game operations -----------------------------//

void	do_sa(t_env *env);

void	do_sb(t_env *env);

void	do_ss(t_env *env);

void	do_pa(t_env *env);

void	do_pb(t_env *env);

void	do_ra(t_env *env);

void	do_rb(t_env *env);

void	do_rr(t_env *env);

void	do_rra(t_env *env);

void	do_rrb(t_env *env);

void	do_rrr(t_env *env);

#endif