/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:19:26 by acami             #+#    #+#             */
/*   Updated: 2021/07/07 15:25:15 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int32_t	readMultiParamInput(t_dCList **a_head, int32_t argc,
const char **argv)
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

static int32_t	readSingleParamInput(t_dCList **a_head, const char *str)
{
	size_t	str_pos;
	size_t	str_len;
	int32_t	count;

	str_pos = 0;
	count = 0;
	str_len = ft_strlen(str);
	while (str_pos < str_len)
	{
		pushDCList(a_head, ft_atol(str + str_pos), false);
		while (ft_isdigit(str[str_pos]) && str_pos < str_len)
			++str_pos;
		while (str[str_pos] == ' ' && str_pos < str_len)
			++str_pos;
		++count;
	}
	printDCList(*a_head);
	return (count);
}

static void	checkArgsValidity(int32_t argc, const char **argv)
{
	int32_t	argnum;
	size_t	count;
	size_t	str_len;

	argnum = 1;
	while (argnum < argc)
	{
		count = 0;
		str_len = ft_strlen(argv[argnum]);
		if (str_len == 0)
			panic(ERRMSG_DEFAULT);
		while (count < str_len)
		{
			if (!(ft_isdigit(argv[argnum][count]))
				&& !((argv[argnum][count] == ' ') && (argc == 2)))
				panic(ERRMSG_DEFAULT);
			++count;
		}
		++argnum;
	}
}

void	parseInput(t_dCList **a_head, int32_t argc, const char **argv)
{
	int32_t	entries;

	checkArgsValidity(argc, argv);
	if (argc > 2)
		entries = readMultiParamInput(a_head, argc, argv);
	else if (argc == 2)
		entries = readSingleParamInput(a_head, argv[1]);
	else
		panic(ERRMSG_DEFAULT);
	// Validate input list
}
