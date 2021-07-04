/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:28:37 by acami             #+#    #+#             */
/*   Updated: 2021/07/04 16:34:50 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static size_t	ft_prepare_number(int64_t n)
{
	size_t	res;
	int64_t	divider;

	res = 19;
	divider = -1000000000000000000;
	if (n >= 0)
	{
		n *= -1;
		--res;
	}
	while (n / divider == 0 && divider != -1)
	{
		divider /= 10;
		--res;
	}
	return (res);
}

static int64_t	basic_pow(int64_t x, int64_t n)
{
	int64_t	res;

	res = x;
	while (n > 1)
	{
		res *= x;
		--n;
	}
	return (res);
}

static char	*ft_generate_num(int64_t n, char *res, size_t num_len,
size_t current_pos)
{
	char		current_digit;
	char		num_started;
	long long	divider;

	num_started = 0;
	divider = -1 * basic_pow(10, num_len - 1);
	while (divider != 0)
	{
		current_digit = n / divider % 10 + 48;
		divider = divider / 10;
		if ((current_digit != '0') || (num_started != 0) || (divider == 0))
		{
			num_started = 1;
			*(res + current_pos) = current_digit;
			++current_pos;
		}
	}
	return (res);
}

char	*ft_ltoa(int64_t n)
{
	char		*res;
	size_t		current_pos;
	size_t		num_len;

	current_pos = 0;
	num_len = ft_prepare_number(n);
	res = malloc((num_len + 1) * sizeof(char));
	if (res == NULL)
		return (res);
	if (n < 0)
	{
		*res = '-';
		++current_pos;
	}
	else
		n = n * -1;
	ft_generate_num(n, res, num_len, current_pos);
	*(res + num_len) = '\0';
	return (res);
}
