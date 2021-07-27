/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:31:03 by acami             #+#    #+#             */
/*   Updated: 2021/07/27 18:56:46 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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

static void	assignBScore(t_env *env, t_dCList *elem, int64_t position)
{
	int64_t	rotation_a_score;
	int64_t	rotation_b_score;

	rotation_a_score = calculate_a_rotations(env, elem->val);
	if (position < env->b_size - position)
		rotation_b_score = position;
	else
		rotation_b_score = position - env->b_size;
}

void	nextMove(t_env *env)
{

}
*/
