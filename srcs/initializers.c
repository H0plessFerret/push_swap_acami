/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:59:36 by acami             #+#    #+#             */
/*   Updated: 2021/07/03 20:06:24 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initActionList(t_actionList *action_list)
{
	action_list->next = NULL;
	action_list->action = act_nothing;
}

void	initEnv(t_env *env)
{
	env->a_head = NULL;
	env->b_head = NULL;
	initActionList(env->actions);
}
