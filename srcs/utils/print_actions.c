/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:50:31 by acami             #+#    #+#             */
/*   Updated: 2021/07/30 15:05:29 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printActions(const t_dCList *actions, int64_t fd)
{
	static const char	*op_names[12] = {
		[act_nothing] = "",
		[act_sa] = "sa",
		[act_sb] = "sb",
		[act_ss] = "ss",
		[act_pa] = "pa",
		[act_pb] = "pb",
		[act_ra] = "ra",
		[act_rb] = "rb",
		[act_rr] = "rr",
		[act_rra] = "rra",
		[act_rrb] = "rrb",
		[act_rrr] = "rrr"
	};
	t_dCList			*curr_action;

	if (actions == NULL)
		return ;
	ft_putendl_fd(op_names[actions->val], fd);
	curr_action = actions->next;
	while (curr_action != actions)
	{
		ft_putendl_fd(op_names[curr_action->val], fd);
		curr_action = curr_action->next;
	}
}
