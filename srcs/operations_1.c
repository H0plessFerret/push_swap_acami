/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:03:59 by acami             #+#    #+#             */
/*   Updated: 2021/07/08 13:18:30 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_env *env)
{
	swap(env->a_head);
	pushAction(&(env->actions), act_sa);
}

void	sb(t_env *env)
{
	swap(env->b_head);
	pushAction(&(env->actions), act_sb);
}

void	pa(t_env *env)
{
	push(&(env->b_head), &(env->a_head));
	pushAction(&(env->actions), act_pa);
}

void	pb(t_env *env)
{
	push(&(env->a_head), &(env->b_head));
	pushAction(&(env->actions), act_pb);
}
