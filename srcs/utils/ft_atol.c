/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:27:14 by acami             #+#    #+#             */
/*   Updated: 2021/07/04 16:38:32 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	ft_is_ignorable(char sym)
{
	if ((sym != '\n') && (sym != ' ') && (sym != '\t')
		&& (sym != '\v') && (sym != '\r') && (sym != '\f'))
		return (0);
	return (1);
}

int64_t	ft_atol(const char *str)
{
	int64_t	sign;
	int64_t	result;

	result = 0;
	sign = 1;
	while (ft_is_ignorable(*str))
		++str;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while ((*str >= '0') && (*str <= '9'))
	{
		result = result * 10 + (*str - '0') * sign;
		++str;
	}
	return (result);
}
