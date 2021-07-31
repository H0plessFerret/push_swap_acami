/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:43:21 by acami             #+#    #+#             */
/*   Updated: 2021/07/31 17:44:05 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char **argv)
{
	t_env		env;

	initEnv(&env);
	parseInput(&env, argc, argv);
	mySort(&env);
	printActions(env.actions, STDOUT_FILENO);
	clearEnv(&env);
	exit (EXIT_SUCCESS);
}
