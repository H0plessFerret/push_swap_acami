/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:00:38 by acami             #+#    #+#             */
/*   Updated: 2021/07/31 15:20:07 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	mySort(t_env *env)
{
	if (isSorted(env->a_head))
		exit(EXIT_SUCCESS);
	if (env->a_size <= 6)
		miniSort(env);
	else
		fullSort(env);
}
