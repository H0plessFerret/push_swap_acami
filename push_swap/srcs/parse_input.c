/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:19:26 by acami             #+#    #+#             */
/*   Updated: 2021/08/04 13:06:31 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int32_t	readMultiParamInput(t_dCList **a_head, int32_t argc,
const char **argv)
{
	int32_t	count;
	int64_t	val;

	count = 1;
	while (count < argc)
	{
		val = ft_atol(argv[count]);
		if (val > INT32_MAX)
			panic(ERRMSG_DEFAULT);
		pushDCList(a_head, val, false);
		++count;
	}
	return (count - 1);
}

static int32_t	readSingleParamInput(t_dCList **a_head, const char *str)
{
	size_t	str_pos;
	size_t	str_len;
	int64_t	val;
	int32_t	count;

	str_pos = 0;
	count = 0;
	str_len = ft_strlen(str);
	while (str_pos < str_len)
	{
		val = ft_atol(str + str_pos);
		if (val > INT32_MAX)
			panic(ERRMSG_DEFAULT);
		pushDCList(a_head, val, false);
		while ((str[str_pos] == '-' || ft_isdigit(str[str_pos]))
			&& str_pos < str_len)
			++str_pos;
		while (str[str_pos] == ' ' && str_pos < str_len)
			++str_pos;
		++count;
	}
	return (count);
}

static void	checkArgsValidity(int32_t argc, const char **argv)
{
	int32_t	arg;
	size_t	count;
	size_t	str_len;

	arg = 1;
	while (arg < argc)
	{
		count = 0;
		str_len = ft_strlen(argv[arg]);
		if (str_len == 0)
			panic(ERRMSG_DEFAULT);
		while (count < str_len)
		{
			if ((!(ft_isdigit(argv[arg][count])) && argv[arg][count] != '-'
					&& !((argv[arg][count] == ' ') && (argc == 2)))
				|| ((argv[arg][count + 1] == '\0'
					|| argv[arg][count + 1] == ' ') && argv[arg][count] == '-')
				|| (count > 0 && (argv[arg][count] == '-'
					&& argv[arg][count - 1] != ' ')))
				panic(ERRMSG_DEFAULT);
			++count;
		}
		++arg;
	}
}

static void	checkListVals(t_dCList *a_head)
{
	t_dCList	*curr_elem;
	t_dCList	*curr_head;

	if (a_head->next != a_head)
	{
		curr_head = a_head;
		while (curr_head != a_head->prev)
		{
			curr_elem = curr_head->next;
			while (curr_elem != a_head)
			{
				if (curr_elem->val == curr_head->val)
					panic(ERRMSG_DEFAULT);
				curr_elem = curr_elem->next;
			}
			curr_head = curr_head->next;
		}
	}
}

void	parseInput(t_env *env, int32_t argc, const char **argv)
{
	int32_t	entries;

	checkArgsValidity(argc, argv);
	entries = 0;
	if (argc > 2)
		entries = readMultiParamInput(&(env->a_head), argc, argv);
	else if (argc == 2)
		entries = readSingleParamInput(&(env->a_head), argv[1]);
	else
		panic(ERRMSG_DEFAULT);
	checkListVals(env->a_head);
	env->a_size = entries;
}
