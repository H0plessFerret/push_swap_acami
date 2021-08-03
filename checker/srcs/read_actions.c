/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:23:23 by acami             #+#    #+#             */
/*   Updated: 2021/08/03 14:10:34 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>
static t_actionId	interpretAction(const char *action_line)
{
	if (strIsEqual(action_line, "sa"))
		return (act_sa);
	else if (strIsEqual(action_line, "sb"))
		return (act_sb);
	else if (strIsEqual(action_line, "ss"))
		return (act_ss);
	else if (strIsEqual(action_line, "pa"))
		return (act_pa);
	else if (strIsEqual(action_line, "pb"))
		return (act_pb);
	else if (strIsEqual(action_line, "ra"))
		return (act_ra);
	else if (strIsEqual(action_line, "rb"))
		return (act_rb);
	else if (strIsEqual(action_line, "rr"))
		return (act_rr);
	else if (strIsEqual(action_line, "rra"))
		return (act_rra);
	else if (strIsEqual(action_line, "rrb"))
		return (act_rrb);
	else if (strIsEqual(action_line, "rrr"))
		return (act_rrr);
	return (act_error);
}

void	readActions(t_env *env, int32_t fd)
{
	char		*action_line;
	t_actionId	act_id;

	while (get_next_line(fd, &action_line) > 0)
	{
		act_id = interpretAction(action_line);
		if (act_id == act_error)
			panic(ERRMSG_DEFAULT);
		pushAction(&(env->actions), act_id);
		free(action_line);
	}
}
