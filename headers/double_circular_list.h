/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_circular_list.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:45:15 by acami             #+#    #+#             */
/*   Updated: 2021/07/03 16:55:20 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_CIRCULAR_LIST_H
# define DOUBLE_CIRCULAR_LIST_H

# include <stdlib.h>
# include <inttypes.h>
# include <stdbool.h>
# include "utils.h"

// DCList = Doubly-linked Circlular List
typedef struct s_dCList	t_dCList;
typedef bool			(*t_comparator)(t_dCList *a, t_dCList *b);

struct s_dCList
{
	int64_t		val;
	t_dCList	*next;
	t_dCList	*prev;
};

t_dCList	*createDCListElem(int64_t val);

void		insertDCList(t_dCList **reference, int64_t val);

void		deleteDCListElem(t_dCList **elem);

void		clearDCList(t_dCList **head);

void		printDCList(t_dCList *head);

#endif
