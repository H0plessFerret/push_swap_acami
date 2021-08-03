/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:03:59 by acami             #+#    #+#             */
/*   Updated: 2021/08/03 13:57:55 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_sa(t_env *env)
{
	swap(env->a_head);
}

void	do_sb(t_env *env)
{
	swap(env->b_head);
}

void	do_pa(t_env *env)
{
	push(&(env->b_head), &(env->a_head));
	if (env->b_size > 0)
	{
		++(env->a_size);
		--(env->b_size);
	}
}

void	do_pb(t_env *env)
{
	push(&(env->a_head), &(env->b_head));
	if (env->a_size > 0)
	{
		--(env->a_size);
		++(env->b_size);
	}
}
