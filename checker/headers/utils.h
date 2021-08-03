/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:14:55 by acami             #+#    #+#             */
/*   Updated: 2021/08/03 13:28:25 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <inttypes.h>
# include <stdbool.h>
# include <unistd.h>

# define	ERRMSG_DEFAULT	"Error"

// Malloc bytes_to_alloc bytes. Exits the programm if malloc returns NULL
void	*xMalloc(size_t bytes_to_alloc);

// Convert string to int64_t value
int64_t	ft_atol(const char *str);

// Returns amount of symbols in a string
size_t	ft_strlen(const char *str);

// Exit the program and print the error message
void	panic(const char *errstr);

// Returns true if character is a digit, and false otherwise
bool	ft_isdigit(int32_t character_to_check);

// Prints a string str to fd
void	ft_putstr_fd(const char *str, int32_t fd);

// Prints a string str to fd and adds a \n afterwards
void	ft_putendl_fd(const char *str, int32_t fd);

// Compares two strings and returns true if they are equal and false otherwise
bool	strIsEqual(const char *s1, const char *s2);

#endif