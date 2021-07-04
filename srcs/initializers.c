/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:59:36 by acami             #+#    #+#             */
/*   Updated: 2021/07/04 17:02:42 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initActionList(t_actionList *action_list)
{
	if (action_list == NULL)
		exit (EXIT_FAILURE);
	action_list->next = NULL;
	action_list->action = act_nothing;
}

static void	clearActionList(t_actionList **action_list)
{
	t_actionList	*to_free;

	to_free = *action_list;
	while (to_free != NULL)
	{
		*action_list = (*action_list)->next;
		free(to_free);
		to_free = *action_list;
	}
	*action_list = NULL;
}

void	initEnv(t_env *env)
{
	env->a_head = NULL;
	env->b_head = NULL;
	initActionList(env->actions);
}

void	clearEnv(t_env *env)
{
	clearDCList(&(env->a_head));
	clearDCList(&(env->b_head));
	clearActionList(&(env->actions));
}
