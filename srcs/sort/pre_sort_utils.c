/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:27:50 by acami             #+#    #+#             */
/*   Updated: 2021/07/31 17:33:47 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int64_t	findScpecialValues(const int64_t *arr, int64_t size, int64_t *min,
int64_t *max)
{
	*min = arr[0];
	*max = arr[size - 1];
	return (arr[size / 2]);
}

// TO DO: Fix this sort maybe, idk it kinda works
static void	sortArray(int64_t *arr, int64_t arr_size)
{
	int64_t	i;
	int64_t	j;
	int64_t	tmp;

	i = 0;
	while (i < arr_size)
	{
		j = i + 1;
		while (j < arr_size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			++j;
		}
		++i;
	}
}

int64_t	*findSortedArray(t_env *env, bool is_a)
{
	t_dCList	*curr_elem;
	int64_t		list_size;
	int64_t		*arr;
	int64_t		count;

	if (is_a)
	{
		list_size = env->a_size;
		curr_elem = env->a_head;
	}
	else
	{
		list_size = env->b_size;
		curr_elem = env->b_head;
	}
	arr = malloc(list_size * sizeof(int64_t));
	count = 0;
	while (count < list_size)
	{
		arr[count] = curr_elem->val;
		curr_elem = curr_elem->next;
		++count;
	}
	sortArray(arr, list_size);
	return (arr);
}

void	pushToB(t_env *env, int64_t min, int64_t max, int64_t mid)
{
	int64_t		count;

	count = 0;
	while (true)
	{
		if (env->a_head->val != min && env->a_head->val != max)
		{
			if (env->a_head->elem_score != SORTED)
			{
				pb(env);
				if (env->b_head->val > mid)
					rb(env);
			}
			else
				ra(env);
		}
		else if (count != 2)
		{
			ra(env);
			++count;
		}
		else
			break ;
	}
}

int64_t	findRotationsToElem(t_dCList *head, int64_t size, int64_t val)
{
	int64_t		count;
	t_dCList	*curr_elem;

	if (head->val == val)
		return (0);
	count = 1;
	curr_elem = head->next;
	while (curr_elem != head)
	{
		if (curr_elem->val == val)
			break ;
		curr_elem = curr_elem->next;
		++count;
	}
	if (count < size - count)
		return (count);
	return (count - size);
}
