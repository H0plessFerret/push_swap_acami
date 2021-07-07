/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:14:41 by acami             #+#    #+#             */
/*   Updated: 2021/07/07 14:04:12 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "double_circular_list.h"
# include "utils.h"
# include <stdlib.h>
# include <inttypes.h>
# include <unistd.h>

typedef struct s_env		t_env;
typedef struct s_actionList	t_actionList;
typedef enum e_actionId		t_actionId;

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

struct s_actionList
{
	t_actionId		action;
	t_actionList	*next;
};

struct s_env
{
	t_dCList		*a_head;
	t_dCList		*b_head;
	t_actionList	*actions;
};

// Initialize environment variables
void	initEnv(t_env *env);

// Free lists and before exiting the program
void	clearEnv(t_env *env);

// Check input for validity and save it (if valid) to a DCList
void	parseInput(t_dCList **a_head, int32_t argc, const char **argv);

#endif