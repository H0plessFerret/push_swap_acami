/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:43:41 by acami             #+#    #+#             */
/*   Updated: 2021/08/03 13:58:08 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_ss(t_env *env)
{
	swap(env->a_head);
	swap(env->b_head);
}

void	do_rr(t_env *env)
{
	rotate(&(env->a_head));
	rotate(&(env->b_head));
}

void	do_rrr(t_env *env)
{
	revRotate(&(env->a_head));
	revRotate(&(env->b_head));
}
