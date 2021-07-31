/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:14:41 by acami             #+#    #+#             */
/*   Updated: 2021/07/31 15:06:58 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "double_circular_list.h"
# include "utils.h"
# include <stdlib.h>
# include <inttypes.h>
# include <unistd.h>

# define	SORTED	1
# define	EFFECTIVENESS_THRESHOLD	3

typedef struct s_env			t_env;
typedef struct s_subarray		t_subarray;
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

struct s_subarray
{
	int64_t	val;
	int64_t	score;
	int64_t	prev_val;
	bool	has_prev_elem;
};

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

// Initialize environment variables
void	initEnv(t_env *env);

// Free lists and before exiting the program
void	clearEnv(t_env *env);

// Check input for validity and save it (if valid) to a DCList
void	parseInput(t_env *env, int32_t argc, const char **argv);

// Algorithm for sorting large amounts of data
void	fullSort(t_env *env);

// Sub-algorithm used for sorting very small chunks of data
void	miniSort(t_env *env);

// Actual sorting function
void	mySort(t_env *env);

// Prints all actions needed to sort an incoming array in the fd specified
void	printActions(const t_dCList *actions, int64_t fd);

// Find the greatest possible sorted sub array
// starting with min and ending with max elem on the A stack
void	findGreatestSortedSubarray(t_env *env, int64_t min, int64_t max);

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

void	rr(t_env *env);

void	rra(t_env *env);

void	rrb(t_env *env);

void	rrr(t_env *env);

//----------------------------- Sort operations -----------------------------//

// Returns mid value, and sets min and max values of an array arr
int64_t	findScpecialValues(const int64_t *arr, int64_t size, int64_t *min,
			int64_t *max);

// If is_a is true - returns a sorted array of the stack A,
// otherwise returns a sorted array of the stack B
int64_t	*findSortedArray(t_env *env, bool is_a);

// Push all unsorted elements to the B stack
void	pushToB(t_env *env, int64_t min, int64_t max, int64_t mid);

// Calculate and do the next step of the algorithm
void	nextMove(t_env *env);

// Check if the array is properly sorted
bool	isSorted(t_dCList *head);

// Find how many rotations of stack a are needed in order
// to push val into a correct position
// Negative value means it's reverse rotations
int64_t	calculateARotations(const t_env *env, int64_t val);

// Do a_rotations on the a list, and b_rotations on the b_list
// If the amount of rotations is negative, it's reverse rotations
// Automatically use rr and rrr if possible
void	doRotations(t_env *env, int64_t a_rotations, int64_t b_rotations);

#endif