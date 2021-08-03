/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 09:16:01 by acami             #+#    #+#             */
/*   Updated: 2021/05/06 12:32:23 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	128
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_fdlist	t_fdlist;
struct s_fdlist
{
	int			fd;
	char		buffer[BUFFER_SIZE];
	size_t		curr_position;
	int			sym_recieved;
	t_fdlist	*next;
};

int			get_next_line(int fd, char **line);
int			ft_read_and_validate(int fd, t_fdlist *fd_buff,
				t_fdlist **head_fdlist);
int			ft_copy_buffer(t_fdlist *fd_buff, char **line,
				int *current_line_pos);
void		*ft_realloc_str(char *line, size_t old_size, size_t new_size);

t_fdlist	*ft_find_or_add(int fd, t_fdlist **head);
void		ft_delelem(t_fdlist *to_del, t_fdlist **head);

int			ft_panic_button(char **line);

#endif
