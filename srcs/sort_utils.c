/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:03 by acami             #+#    #+#             */
/*   Updated: 2021/07/29 12:55:19 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find how many rotations of stack a are needed in order
// to push val into a correct position
// Negative value means it's reverse rotations
static int64_t	calculateARotations(t_env *env, int64_t val)
{
	t_dCList	*curr_elem;
	int64_t		count;

	count = 0;
	curr_elem = env->a_head;
	while (val > curr_elem->val)
	{
		curr_elem = curr_elem->next;
		++count;
	}
	if (count < env->a_size - count)
		return (count);
	return (count - env->a_size);
}

// Assign the amount of actions needed to set elem into a correct position
// to every b_stack element
static void	assignBScore(t_env *env, t_dCList *elem, int64_t position)
{
	int64_t	rotation_a_score;
	int64_t	rotation_b_score;

	rotation_a_score = calculate_a_rotations(env, elem->val);
	if (position < env->b_size - position)
		rotation_b_score = position;
	else
		rotation_b_score = position - env->b_size;
	if ((rotation_a_score > 0 && rotation_b_score > 0)
		|| (rotation_a_score < 0 && rotation_b_score < 0))
	{
		if (myAbs(rotation_a_score) > myAbs(rotation_b_score))
			elem->elem_score = myAbs(rotation_a_score);
		else
			elem->elem_score = myAbs(rotation_b_score);
	}
	else
		elem->elem_score = myAbs(rotation_a_score) + myAbs(rotation_b_score);
}

// Find an elem with the lowest score in b_stack
static t_dCList	*findBMinScoreElem(t_env *env)
{
	int64_t		count;
	t_dCList	*curr_elem;
	t_dCList	*min_score_elem;

	count = 1;
	min_score_elem = env->b_head;
	curr_elem = env->b_head->next;
	while (count < env->b_size)
	{
		if (curr_elem->elem_score < min_score_elem->elem_score)
			min_score_elem = curr_elem;
		curr_elem = curr_elem->next;
		++count;
	}
	return (min_score_elem);
}

void	nextMove(t_env *env)
{
	int64_t		count;
	t_dCList	*curr_elem;
	t_dCList	*min_score_elem;

	count = 0;
	curr_elem = env->b_head;
	while (count < env->b_size)
	{
		assignBScore(env, curr_elem, count);
		curr_elem = curr_elem->next;
		++count;
	}
	min_score_elem = findBMinScoreElem(env);
	//pushBMinScoreElem
}
