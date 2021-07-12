/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:14:41 by acami             #+#    #+#             */
/*   Updated: 2021/07/12 15:09:22 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "double_circular_list.h"
# include "utils.h"
# include <stdlib.h>
# include <inttypes.h>
# include <unistd.h>

typedef struct s_env			t_env;
typedef enum e_actionId			t_actionId;

enum e_actionId
{
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

struct s_env
{
	t_dCList	*a_head;
	t_dCList	*b_head;
	t_dCList	*actions;
	int64_t		elems_total;
};

// Initialize environment variables
void	initEnv(t_env *env);

// Free lists and before exiting the program
void	clearEnv(t_env *env);

// Check input for validity and save it (if valid) to a DCList
void	parseInput(t_env *env, int32_t argc, const char **argv);

// Actual sorting function
void	mySort(t_env *env);

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

void	sa(t_env *env);

void	sb(t_env *env);

void	pa(t_env *env);

void	pb(t_env *env);

void	ra(t_env *env);

void	rb(t_env *env);

void	rra(t_env *env);

void	rrb(t_env *env);

#endif