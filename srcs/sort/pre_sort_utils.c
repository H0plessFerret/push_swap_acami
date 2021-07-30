/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:27:50 by acami             #+#    #+#             */
/*   Updated: 2021/07/30 17:38:02 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	findScpecialValues(const t_env *env, int64_t *min,
int64_t *max, int64_t *mid)
{
	*min = env->desired_array[0];
	*max = env->desired_array[env->a_size - 1];
	*mid = env->desired_array[env->a_size / 2];
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

void	findDeisredArray(t_env *env)
{
	t_dCList	*curr_elem;
	int64_t		count;

	env->desired_array = malloc(env->a_size * sizeof(int64_t));
	curr_elem = env->a_head;
	count = 0;
	while (count < env->a_size)
	{
		env->desired_array[count] = curr_elem->val;
		curr_elem = curr_elem->next;
		++count;
	}
	sortArray(env->desired_array, env->a_size);
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
				if (env->b_head->val >= mid)
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
