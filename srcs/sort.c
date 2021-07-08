/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:57:29 by acami             #+#    #+#             */
/*   Updated: 2021/07/08 15:48:01 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int64_t	findMax(t_dCList *head)
{
	int64_t		max;
	t_dCList	*curr_elem;

	max = head->val;
	curr_elem = head->next;
	while (curr_elem != head)
	{
		if (curr_elem->val > max)
			max = curr_elem->val;
		curr_elem = curr_elem->next;
	}
	return (max);
}

static int64_t	findMin(t_dCList *head)
{
	int64_t		min;
	t_dCList	*curr_elem;

	min = head->val;
	curr_elem = head->next;
	while (curr_elem != head)
	{
		if (curr_elem->val < min)
			min = curr_elem->val;
		curr_elem = curr_elem->next;
	}
	return (min);
}

static int64_t	rotationsNeeded(t_env *env)
{
	int64_t		b_head_val;
	t_dCList	*curr_a_pos;
	int64_t		count;

	b_head_val = env->b_head->val;
	curr_a_pos = env->a_head;
	count = 0;
	while (!(curr_a_pos->prev->val < b_head_val && b_head_val < curr_a_pos->val))
	{
		curr_a_pos = curr_a_pos->next;
		++count;
	}
	return (count);
}

static int64_t	revRotationsNeeded(t_env *env)
{
	int64_t		b_head_val;
	t_dCList	*curr_a_pos;
	int64_t		count;

	b_head_val = env->b_head->val;
	curr_a_pos = env->a_head;
	count = 0;
	while (!(curr_a_pos->prev->val < b_head_val && b_head_val < curr_a_pos->val))
	{
		curr_a_pos = curr_a_pos->prev;
		++count;
	}
	return (count);
}

void	mySort(t_env *env)
{
	int64_t	max;
	int64_t	min;
	int64_t	rot;
	int64_t	rev_rot;
	int64_t	count;

	max = findMax(env->a_head);
	min = findMin(env->a_head);
	count = 0;
	while (count < 3)
	{
		if (env->a_head->val != min && env->a_head->val != max)
			pb(env);
		else
		{
			ra(env);
			++count;
		}
	}
	while (env->b_head != NULL)
	{
		rot = rotationsNeeded(env);
		rev_rot = revRotationsNeeded(env);
		if (rot > rev_rot)
		{
			while (rev_rot > 0)
			{
				rra(env);
				--rev_rot;
			}
		}
		else
		{
			while (rot > 0)
			{
				ra(env);
				--rot;
			}
		}
		pa(env);
	}
	while (env->a_head->val != min)
		ra(env);
}
