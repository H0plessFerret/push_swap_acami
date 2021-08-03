/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:04:17 by acami             #+#    #+#             */
/*   Updated: 2021/08/03 13:58:01 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_ra(t_env *env)
{
	rotate(&(env->a_head));
}

void	do_rb(t_env *env)
{
	rotate(&(env->b_head));
}

void	do_rra(t_env *env)
{
	revRotate(&(env->a_head));
}

void	do_rrb(t_env *env)
{
	revRotate(&(env->b_head));
}
