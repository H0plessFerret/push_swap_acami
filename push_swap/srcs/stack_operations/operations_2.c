/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:04:17 by acami             #+#    #+#             */
/*   Updated: 2021/07/08 13:19:05 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_env *env)
{
	rotate(&(env->a_head));
	pushAction(&(env->actions), act_ra);
}

void	rb(t_env *env)
{
	rotate(&(env->b_head));
	pushAction(&(env->actions), act_rb);
}

void	rra(t_env *env)
{
	revRotate(&(env->a_head));
	pushAction(&(env->actions), act_rra);
}

void	rrb(t_env *env)
{
	revRotate(&(env->b_head));
	pushAction(&(env->actions), act_rrb);
}
