/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_circular_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:08:48 by acami             #+#    #+#             */
/*   Updated: 2021/07/03 17:21:42 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_circular_list.h"
#include <stdio.h>

t_dCList	*createDCListElem(int64_t val)
{
	t_dCList	*new_elem;

	new_elem = xMalloc(sizeof(t_dCList));
	new_elem->next = new_elem;
	new_elem->prev = new_elem;
	new_elem->val = val;
	return (new_elem);
}

void	insertDCList(t_dCList **reference, int64_t val)
{
	t_dCList	*new_elem;

	new_elem = createDCListElem(val);
	if (*reference == NULL)
	{
		*reference = new_elem;
		return ;
	}
	new_elem->next = (*reference)->next;
	new_elem->prev = *reference;
	(*reference)->next->prev = new_elem;
	(*reference)->next = new_elem;
}

void	deleteDCListElem(t_dCList **elem)
{
	if ((*elem)->next == *elem)
	{
		free(*elem);
		*elem = NULL;
		return ;
	}
	(*elem)->next->prev = (*elem)->prev;
	(*elem)->prev->next = (*elem)->next;
	free(*elem);
}

void	clearDCList(t_dCList **head)
{
	t_dCList	*curr_elem;

	if (*head == NULL)
		return ;
	curr_elem = (*head)->next;
	while (curr_elem != *head)
	{
		free(curr_elem);
		curr_elem = curr_elem->next;
	}
	free(curr_elem);
	*head = NULL;
}

void	printDCList(t_dCList *head)
{
	t_dCList	*curr_elem;

	curr_elem = head;
	while (curr_elem->next != head)
	{
		printf("%lld\n", curr_elem->val);
		curr_elem = curr_elem->next;
	}
	printf("%lld\n", curr_elem->val);
}
