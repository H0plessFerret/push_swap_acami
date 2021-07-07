/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:17:21 by acami             #+#    #+#             */
/*   Updated: 2021/07/07 14:13:35 by acami            ###   ########.fr       */
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

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*(str + count) != '\0')
		++count;
	return (count);
}

bool	ft_isdigit(int32_t character_to_check)
{
	if ((character_to_check >= '0') && (character_to_check <= '9'))
		return (true);
	return (false);
}

void	ft_putstr_fd(char *str, int32_t fd)
{
	if (str != NULL)
		write(fd, str, ft_strlen(str));
}

void	ft_putendl_fd(char *str, int32_t fd)
{
	if (str != NULL)
	{
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
	}
}
