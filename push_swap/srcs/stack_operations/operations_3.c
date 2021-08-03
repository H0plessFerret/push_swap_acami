/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:43:41 by acami             #+#    #+#             */
/*   Updated: 2021/07/30 14:44:25 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_env *env)
{
	rotate(&(env->a_head));
	rotate(&(env->b_head));
	pushAction(&(env->actions), act_rr);
}

void	rrr(t_env *env)
{
	revRotate(&(env->a_head));
	revRotate(&(env->b_head));
	pushAction(&(env->actions), act_rrr);
}
