/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:14:04 by acami             #+#    #+#             */
/*   Updated: 2021/07/31 16:22:26 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sort 3 elems on the A stack
static void	sortAThree(t_env *env)
{
	int64_t	min;
	int64_t	max;
	int64_t	mid;
	int64_t	*sorted_a_arr;

	sorted_a_arr = findSortedArray(env, true);
	mid = findScpecialValues(sorted_a_arr, env->a_size, &min, &max);
	if (env->a_head->val == max)
		ra(env);
	if (env->a_head->val == mid)
	{
		if (env->a_head->next->val == max)
			rra(env);
		else
			sa(env);
		return ;
	}
	if (env->a_head->next->val == max)
	{
		rra(env);
		sa(env);
	}
}

// Sort 3 elems on the B stack
static void	sortBThree(t_env *env)
{
	int64_t	min;
	int64_t	max;
	int64_t	mid;
	int64_t	*sorted_b_arr;

	sorted_b_arr = findSortedArray(env, false);
	mid = findScpecialValues(sorted_b_arr, env->b_size, &min, &max);
	if (env->b_head->val == max)
		rb(env);
	if (env->b_head->val == mid)
	{
		if (env->b_head->next->val == max)
			rrb(env);
		else
			sb(env);
		return ;
	}
	if (env->b_head->next->val == max)
	{
		rrb(env);
		sb(env);
	}
}

// Check if val is greater than any other value in a stack
static bool	isMaxInStack(t_dCList *head, int64_t val)
{
	t_dCList	*curr_elem;

	if (head->val > val)
		return (false);
	curr_elem = head->next;
	while (curr_elem != head)
	{
		if (curr_elem->val > val)
			return (false);
		curr_elem = curr_elem->next;
	}
	return (true);
}

// Joins two stacks on A while maintaining the order of elements
static void	joinThrees(t_env *env, int64_t min)
{
	int64_t	a_rotations;

	while (env->b_size != 0)
	{
		if (env->b_head->val < env->a_head->val)
			pa(env);
		else if (isMaxInStack(env->a_head, env->b_head->val)
			&& env->a_head->val == min)
			pa(env);
		ra(env);
	}
	a_rotations = calculateARotations(env, min) - 1;
	doRotations(env, a_rotations, 0);
}

void	miniSort(t_env *env)
{
	int64_t	max;
	int64_t	min;
	int64_t	*sorted_a_arr;

	if (env->a_size == 2)
	{
		sa(env);
		return ;
	}
	sorted_a_arr = findSortedArray(env, true);
	findScpecialValues(sorted_a_arr, env->a_size, &min, &max);
	while (env->a_size > 3)
		pb(env);
	sortAThree(env);
	if (env->b_size == 2 && !isSorted(env->b_head))
		sb(env);
	else if (env->b_size == 3)
		sortBThree(env);
	joinThrees(env, min);
}
