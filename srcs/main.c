/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:53:26 by acami             #+#    #+#             */
/*   Updated: 2021/07/03 17:24:17 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_dCList	*head;
	int32_t		count;

	head = NULL;
	//insertDCList(&head, 6);
	//printDCList(head);
	count = 1;
	while (count < 6)
	{
		//insertDCList(&head, count);
		++count;
	}
	//printDCList(head);
	//clearDCList(&head);
	printf("%p\n", head);
	return (0);
}
