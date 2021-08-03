/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:33:16 by acami             #+#    #+#             */
/*   Updated: 2021/08/03 13:57:50 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_dCList **head)
{
	if (*head == NULL)
		return ;
	*head = (*head)->next;
}

void	revRotate(t_dCList **head)
{
	if (*head == NULL)
		return ;
	*head = (*head)->prev;
}

void	swap(t_dCList *head)
{
	int64_t	temp;

	if (head == NULL || head->next == head)
		return ;
	temp = head->val;
	head->val = head->next->val;
	head->next->val = temp;
}

void	push(t_dCList **from_head, t_dCList **to_head)
{
	t_dCList	*new_from_head;

	if (from_head == NULL || *from_head == NULL)
		return ;
	new_from_head = NULL;
	if (*from_head != (*from_head)->next)
	{
		new_from_head = (*from_head)->next;
		new_from_head->prev = (*from_head)->prev;
		(*from_head)->prev->next = new_from_head;
	}
	if (*to_head == NULL)
	{
		(*from_head)->next = *from_head;
		(*from_head)->prev = *from_head;
	}
	else
	{
		(*from_head)->next = *to_head;
		(*to_head)->prev->next = *from_head;
		(*from_head)->prev = (*to_head)->prev;
		(*to_head)->prev = *from_head;
	}
	*to_head = *from_head;
	*from_head = new_from_head;
}

void	pushAction(t_dCList **head, t_actionId action)
{
	pushDCList(head, action, false);
}
