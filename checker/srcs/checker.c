/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:04:12 by acami             #+#    #+#             */
/*   Updated: 2021/08/03 14:10:50 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, const char **argv)
{
	t_env		env;

	initEnv(&env);
	parseInput(&env, argc, argv);
	readActions(&env, STDIN_FILENO);
	doActions(&env);
	if (isSorted(env.a_head) && env.b_size == 0)
		ft_putendl_fd("\033[0;32mOK\033[0m", STDOUT_FILENO);
	else
		ft_putendl_fd("\033[0;31mKO\033[0m", STDOUT_FILENO);
	clearEnv(&env);
	exit (EXIT_SUCCESS);
}
