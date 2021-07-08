/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_circular_list.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:45:15 by acami             #+#    #+#             */
/*   Updated: 2021/07/08 15:41:45 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_CIRCULAR_LIST_H
# define DOUBLE_CIRCULAR_LIST_H

# include <stdlib.h>
# include <inttypes.h>
# include <stdbool.h>
# include "utils.h"

#include <stdio.h>

// DCList = Doubly-linked Circlular List
typedef struct s_dCList	t_dCList;
typedef bool			(*t_comparator)(t_dCList *a, t_dCList *b);

struct s_dCList
{
	int64_t		val;
	t_dCList	*next;
	t_dCList	*prev;
};

// Create a new element and push it into a list.
// If is_front is set to true, uses makes the new elem the head of the list
// Otherwise makes adds it to the back of the list
void		pushDCList(t_dCList **head, int64_t val, bool is_front);

// Destroys the head elem of DCList, keeps the structure of the list intact
void		deleteDCListHead(t_dCList **head);

// Delete all elements of the DCList and sets the head value to NULL
void		clearDCList(t_dCList **head);

// DEBUG FUNC!
void		printDCList(t_dCList *head);

#endif
