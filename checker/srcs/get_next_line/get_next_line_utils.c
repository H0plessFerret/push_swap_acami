/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 09:40:58 by acami             #+#    #+#             */
/*   Updated: 2021/05/06 12:06:05 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fdlist	*ft_create_elem(int fd)
{
	t_fdlist	*res;

	res = malloc(sizeof(t_fdlist));
	if (res == NULL)
		return (NULL);
	res->next = NULL;
	res->fd = fd;
	res->curr_position = 0;
	res->sym_recieved = 0;
	return (res);
}

t_fdlist	*ft_find_or_add(int fd, t_fdlist **head)
{
	t_fdlist	*elem;

	if (*head == NULL)
	{
		*head = ft_create_elem(fd);
		return (*head);
	}
	if ((*head)->fd == fd)
		return (*head);
	elem = *head;
	while (elem->next != NULL)
	{
		if (elem->next->fd == fd)
			return (elem->next);
		elem = elem->next;
	}
	elem->next = ft_create_elem(fd);
	return (elem->next);
}

void	ft_delelem(t_fdlist *to_del, t_fdlist **head)
{
	t_fdlist	*curr;

	if (*head == to_del)
	{
		curr = *head;
		*head = (*head)->next;
		free(curr);
	}
	else
	{
		curr = *head;
		while (curr->next != NULL)
		{
			if (curr->next == to_del)
			{
				curr->next = to_del->next;
				free(to_del);
				return ;
			}
			curr = curr->next;
		}
	}
}

void	*ft_realloc_str(char *line, size_t old_size, size_t new_size)
{
	char	*buff;
	size_t	count;

	buff = line;
	line = malloc(new_size);
	if (line == NULL)
		return (NULL);
	count = 0;
	if (buff != NULL)
	{
		if (new_size < old_size)
			old_size = new_size;
		while (count < old_size)
		{
			line[count] = buff[count];
			++count;
		}
		free(buff);
	}
	return (line);
}

int	ft_panic_button(char **line)
{
	free(*line);
	*line = NULL;
	return (-1);
}
