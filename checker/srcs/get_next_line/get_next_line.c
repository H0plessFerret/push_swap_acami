/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 09:20:47 by acami             #+#    #+#             */
/*   Updated: 2021/05/06 12:34:17 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static t_fdlist	*head_fdlist = NULL;
	t_fdlist		*fd_buff;
	int				copy_result;
	int				current_line_pos;

	*line = NULL;
	current_line_pos = 0;
	fd_buff = ft_find_or_add(fd, &head_fdlist);
	if (fd_buff == NULL)
		return (ft_panic_button(line));
	while (1)
	{
		if (ft_read_and_validate(fd, fd_buff, &head_fdlist) == -1)
			return (ft_panic_button(line));
		copy_result = ft_copy_buffer(fd_buff, line, &current_line_pos);
		if (copy_result == 0)
			ft_delelem(fd_buff, &head_fdlist);
		if (copy_result != 2)
			return (copy_result);
	}
}

int	ft_read_and_validate(int fd, t_fdlist *fd_buff, t_fdlist **head_fdlist)
{
	if (fd_buff->curr_position == 0)
	{
		fd_buff->sym_recieved = read(fd, fd_buff->buffer, BUFFER_SIZE);
		if (fd_buff->sym_recieved == -1)
		{
			ft_delelem(fd_buff, head_fdlist);
			return (-1);
		}
	}
	return (1);
}

static int	ft_find_endl(t_fdlist *fd_buff, bool *endl_found)
{
	int	shifted_pos;

	shifted_pos = fd_buff->curr_position;
	while (shifted_pos < fd_buff->sym_recieved
		&& fd_buff->buffer[shifted_pos] != '\n')
	{
		++shifted_pos;
	}
	if (shifted_pos < fd_buff->sym_recieved)
		*endl_found = true;
	else
		*endl_found = false;
	return (shifted_pos - fd_buff->curr_position);
}

static int	ft_set_ret_val(t_fdlist *fd_buff, bool endl_found)
{
	if (endl_found)
	{
		if (fd_buff->curr_position + 1 == (size_t)(fd_buff->sym_recieved))
			fd_buff->curr_position = 0;
		else
			++(fd_buff->curr_position);
		return (1);
	}
	if (fd_buff->sym_recieved == 0)
		return (0);
	fd_buff->curr_position = 0;
	return (2);
}

int	ft_copy_buffer(t_fdlist *fd_buff, char **line, int *current_line_pos)
{
	int		required_len;
	bool	endl_found;

	required_len = *current_line_pos + ft_find_endl(fd_buff, &endl_found);
	*line = ft_realloc_str(*line, *current_line_pos, required_len + 1);
	if (*line == NULL)
		return (ft_panic_button(line));
	while (*current_line_pos < required_len)
	{
		(*line)[*current_line_pos] = fd_buff->buffer[fd_buff->curr_position];
		++(*current_line_pos);
		++(fd_buff->curr_position);
	}
	(*line)[*current_line_pos] = '\0';
	return (ft_set_ret_val(fd_buff, endl_found));
}
