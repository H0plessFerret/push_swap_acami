/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_optimization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:26:06 by acami             #+#    #+#             */
/*   Updated: 2021/07/30 18:04:33 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_subarray	*initSubarray(const t_env *env, int64_t min)
{
	t_subarray	*arr;
	t_dCList	*curr_elem;
	int64_t		count;

	arr = xMalloc(sizeof(t_subarray) * (env->a_size));
	curr_elem = env->a_head;
	while (curr_elem->val != min)
		curr_elem = curr_elem->next;
	count = 0;
	while (count < env->a_size)
	{
		arr[count].val = curr_elem->val;
		arr[count].has_prev_elem = false;
		curr_elem = curr_elem->next;
		++count;
	}
	arr[0].score = 1;
	return (arr);
}

static void	processSubarray(const t_env *env, t_subarray *arr, int64_t max)
{
	int64_t		i;
	int64_t		j;
	bool		max_encountered;

	i = 1;
	max_encountered = false;
	while (i < env->a_size && !max_encountered)
	{
		arr[i].score = 0;
		j = 0;
		while (j < i)
		{
			if (arr[i].val == max)
				max_encountered = true;
			if (arr[i].val > arr[j].val && arr[i].score <= arr[j].score)
			{
				arr[i].score = arr[j].score + 1;
				arr[i].prev_val = arr[j].val;
				arr[i].has_prev_elem = true;
			}
			++j;
		}
		++i;
	}
}

static void	markSubarray(t_env *env, t_subarray *arr, int64_t max)
{
	t_dCList	*curr_elem;
	int64_t		count;
	int64_t		prev_val;

	curr_elem = env->a_head;
	while (curr_elem->val != max)
		curr_elem = curr_elem->next;
	count = 0;
	while (arr[count].val != max)
		++count;
	prev_val = arr[count].prev_val;
	curr_elem->elem_score = SORTED;
	while (count > 0)
	{
		if (arr[count].val == prev_val)
		{
			curr_elem->elem_score = SORTED;
			prev_val = arr[count].prev_val;
		}
		--count;
		curr_elem = curr_elem->prev;
	}
	curr_elem->elem_score = SORTED;
}

void	findGreatestSortedSubarray(t_env *env, int64_t min, int64_t max)
{
	t_subarray	*arr;

	arr = initSubarray(env, min);
	processSubarray(env, arr, max);
	markSubarray(env, arr, max);
	free(arr);
}
