/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:00:38 by acami             #+#    #+#             */
/*   Updated: 2021/07/12 16:56:16 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	findScpecialValues(const t_env *env, int64_t *min,
int64_t *max, int64_t *mid)
{
	*min = env->desired_array[0];
	*max = env->desired_array[env->elems_total - 1];
	*mid = env->desired_array[env->elems_total / 2];
}

static void	pushToB(t_env *env)
{
	int64_t		min;
	int64_t		max;
	int64_t		mid;
	int64_t		count;

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
}

static void	findDeisredArray(t_env *env)
{
	t_dCList	*curr_elem;
	int64_t		count;

	env->desired_array = malloc(env->elems_total * sizeof(int64_t));
	curr_elem = env->a_head;
	count = 0;
	while (count < env->elems_total)
	{
		env->desired_array[count] = curr_elem->val;
		curr_elem = curr_elem->next;
		++count;
	}
	//sort array
}

void	mySort(t_env *env)
{
	int64_t	min;
	int64_t	max;
	int64_t	mid;

	// Pre sort if I cba lol
	findDeisredArray(env);
	findScpecialValues(env->a_head, &min, &max, &mid);
	pushToB(env);
	// While b is not empty
	// find next move
}
 