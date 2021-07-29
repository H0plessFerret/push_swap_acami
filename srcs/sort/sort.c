/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:00:38 by acami             #+#    #+#             */
/*   Updated: 2021/07/29 15:36:25 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	doRotations(t_env *env, int64_t a_rotations, int64_t b_rotations)
{
	while (b_rotations < 0)
	{
		rrb(env);
		++b_rotations;
	}
	while (b_rotations > 0)
	{
		rb(env);
		--b_rotations;
	}
	while (a_rotations < 0)
	{
		rra(env);
		++a_rotations;
	}
	while (a_rotations > 0)
	{
		ra(env);
		--a_rotations;
	}
}

void	mySort(t_env *env)
{
	int64_t	min;
	int64_t	max;
	int64_t	mid;
	int64_t	a_rotations;

	// Pre sort if I cba lol
	findDeisredArray(env);
	findScpecialValues(env, &min, &max, &mid);
	pushToB(env, min, max, mid);
	if (env->a_head->val == max)
		sa(env);
	while (env->b_head != NULL)
		nextMove(env);
	a_rotations = calculateARotations(env, min) - 1;
	doRotations(env, a_rotations, 0);
	// Optimize actions
	// Print actions
}
