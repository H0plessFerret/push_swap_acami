/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:59:36 by acami             #+#    #+#             */
/*   Updated: 2021/07/31 15:18:47 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initEnv(t_env *env)
{
	env->a_head = NULL;
	env->b_head = NULL;
	env->actions = NULL;
	env->a_size = 0;
	env->b_size = 0;
}

void	clearEnv(t_env *env)
{
	clearDCList(&(env->a_head));
	clearDCList(&(env->b_head));
	clearDCList(&(env->actions));
}
