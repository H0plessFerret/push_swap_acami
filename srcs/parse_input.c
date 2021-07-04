/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:19:26 by acami             #+#    #+#             */
/*   Updated: 2021/07/04 16:58:10 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int32_t	readMultiParamInput(t_dCList **a_head, int32_t argc,
char **argv)
{
	int32_t	count;

	count = 1;
	while (count < argc)
	{
		pushDCList(a_head, ft_atol(argv[count]), false);
		++count;
	}
	printDCList(*a_head);
	return (count);
}

static int32_t	readSingleParamInput(t_dCList **a_head, int32_t argc,
char **argv)
{
	int32_t	count;

	count = 1;
	while (count < argc)
	{
		pushDCList(a_head, ft_atol(argv[count]), false);
		++count;
	}
	printDCList(*a_head);
	return (count);
}

static void	errorPlaceholder(void)
{
	write(1, "Error\n", 6);
	exit (EXIT_FAILURE);
}

void	parseInput(t_dCList **a_head, int32_t argc, char **argv)
{
	int32_t	entries;

	// Validate input strings
	if (argc > 2)
		entries = readMultiParamInput(a_head, argc, argv);
	else if (argc == 2)
		entries = readSingleParamInput(a_head, argc, argv);
	else
	{
		errorPlaceholder();
	}
	// Validate input list
}
