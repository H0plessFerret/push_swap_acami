/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:44:16 by acami             #+#    #+#             */
/*   Updated: 2021/08/03 14:03:09 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	isSorted(t_dCList *head)
{
	t_dCList	*curr_elem;
	t_dCList	*last;

	curr_elem = head;
	last = head->prev;
	while (curr_elem != last)
	{
		if (curr_elem->val > curr_elem->next->val)
			return (false);
		curr_elem = curr_elem->next;
	}
	return (true);
}

void	doActions(t_env *env)
{
	static const t_operation	do_op[12] = {
		[act_sa] = do_sa,
		[act_sb] = do_sb,
		[act_ss] = do_ss,
		[act_pa] = do_pa,
		[act_pb] = do_pb,
		[act_ra] = do_ra,
		[act_rb] = do_rb,
		[act_rr] = do_rr,
		[act_rra] = do_rra,
		[act_rrb] = do_rrb,
		[act_rrr] = do_rrr
	};
	t_dCList					*curr_elem;

	do_op[env->actions->val % 12](env);
	curr_elem = env->actions->next;
	while (curr_elem != env->actions)
	{
		do_op[curr_elem->val % 12](env);
		curr_elem = curr_elem->next;
	}
}
