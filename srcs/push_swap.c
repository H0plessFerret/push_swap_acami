/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:43:21 by acami             #+#    #+#             */
/*   Updated: 2021/07/30 15:08:37 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static void	debugOutput(t_env *env)
{
	int64_t		action_count;
	t_dCList	*action_iter;

	printf("\nA Size: %ld\n", env->a_size);
	printf("A:\n");
	printDCList(env->a_head);
	printf("\nB Size: %ld\n", env->b_size);
	printf("\nB:\n");
	printDCList(env->b_head);
	action_iter = env->actions->next;
	action_count = 1;
	while (action_iter != env->actions)
	{
		++action_count;
		action_iter = action_iter->next;
	}
	printf("\nActions: %ld", action_count);
	printf("\n");
}
*/

int	main(int argc, const char **argv)
{
	t_env		env;

	initEnv(&env);
	parseInput(&env, argc, argv);
	mySort(&env);
	//clearEnv(&env);
	exit (0);
}
