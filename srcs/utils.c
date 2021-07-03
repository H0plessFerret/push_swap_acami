/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:17:21 by acami             #+#    #+#             */
/*   Updated: 2021/07/03 16:19:41 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	*xMalloc(size_t bytes_to_alloc)
{
	void	*mem;

	mem = malloc(bytes_to_alloc);
	if (mem == NULL)
		exit(EXIT_FAILURE);
	return (mem);
}
