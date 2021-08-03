/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:41:12 by acami             #+#    #+#             */
/*   Updated: 2021/07/30 14:39:01 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int64_t	myAbs(int64_t num)
{
	if (num > 0)
		return (num);
	return (-1 * num);
}

int64_t	myMax(int64_t a, int64_t b)
{
	if (a > b)
		return (a);
	return (b);
}

int64_t	myMin(int64_t a, int64_t b)
{
	if (a < b)
		return (a);
	return (b);
}

int64_t	myMaxAbs(int64_t a, int64_t b)
{
	if (myAbs(a) > myAbs(b))
		return (a);
	return (b);
}

int64_t	myMinAbs(int64_t a, int64_t b)
{
	if (myAbs(a) < myAbs(b))
		return (a);
	return (b);
}
