/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_circular_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:08:48 by acami             #+#    #+#             */
/*   Updated: 2021/07/08 13:42:33 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_circular_list.h"
#include <stdio.h>

static t_dCList	*createDCListElem(int64_t val)
{
	t_dCList	*new_elem;

	new_elem = xMalloc(sizeof(t_dCList));
	new_elem->next = new_elem;
	new_elem->prev = new_elem;
	new_elem->val = val;
	return (new_elem);
}

void	pushDCList(t_dCList **head, int64_t val, bool is_front)
{
	t_dCList	*new_elem;

	new_elem = createDCListElem(val);
	if (*head == NULL)
	{
		*head = new_elem;
		return ;
	}
	new_elem->next = *head;
	new_elem->prev = (*head)->prev;
	(*head)->prev->next = new_elem;
	(*head)->prev = new_elem;
	if (is_front)
		*head = new_elem;
}

void	deleteDCListHead(t_dCList **head)
{
	t_dCList	*tmp;

	if ((*head)->next == *head)
	{
		free(*head);
		*head = NULL;
		return ;
	}
	(*head)->next->prev = (*head)->prev;
	(*head)->prev->next = (*head)->next;
	tmp = (*head)->next;
	free(*head);
	*head = tmp;
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

	if (head == NULL)
		return ;
	curr_elem = head;
	while (curr_elem->next != head)
	{
		printf("%lld\n", curr_elem->val);
		curr_elem = curr_elem->next;
	}
	printf("%lld\n", curr_elem->val);
}
