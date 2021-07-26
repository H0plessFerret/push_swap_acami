/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:33:16 by acami             #+#    #+#             */
/*   Updated: 2021/07/26 15:42:30 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// TO DO: Rewrite this func so it doesn't constantly realloc memory
void	push(t_dCList **from_head, t_dCList **to_head)
{
	if (from_head == NULL)
		return ;
	pushDCList(to_head, (*from_head)->val, true);
	deleteDCListHead(from_head);
}

void	pushAction(t_dCList **head, t_actionId action)
{
	pushDCList(head, action, false);
}
