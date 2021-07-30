/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:12:19 by acami             #+#    #+#             */
/*   Updated: 2021/07/30 18:05:39 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	doCombinedRotations(t_env *env, int64_t *a_rotations,
int64_t *b_rotations)
{
	while (*a_rotations > 0 && *b_rotations > 0)
	{
		rr(env);
		--(*a_rotations);
		--(*b_rotations);
	}
	while (*a_rotations < 0 && *b_rotations < 0)
	{
		rrr(env);
		++(*a_rotations);
		++(*b_rotations);
	}
}

static void	doSimpleRotations(t_env *env, int64_t *a_rotations,
int64_t *b_rotations)
{
	while (*b_rotations < 0)
	{
		rrb(env);
		++(*b_rotations);
	}
	while (*b_rotations > 0)
	{
		rb(env);
		--(*b_rotations);
	}
	while (*a_rotations < 0)
	{
		rra(env);
		++(*a_rotations);
	}
	while (*a_rotations > 0)
	{
		ra(env);
		--(*a_rotations);
	}
}

void	doRotations(t_env *env, int64_t a_rotations, int64_t b_rotations)
{
	doCombinedRotations(env, &a_rotations, &b_rotations);
	doSimpleRotations(env, &a_rotations, &b_rotations);
}

void	fullSort(t_env *env)
{
	int64_t	min;
	int64_t	max;
	int64_t	mid;
	int64_t	a_rotations;

	findDeisredArray(env);
	findScpecialValues(env, &min, &max, &mid);
	findGreatestSortedSubarray(env, min, max);
	pushToB(env, min, max, mid);
	if (env->a_head->val == max)
		ra(env);
	while (env->b_head != NULL)
		nextMove(env);
	a_rotations = calculateARotations(env, min) - 1;
	doRotations(env, a_rotations, 0);
	printActions(env->actions, STDOUT_FILENO);
}
