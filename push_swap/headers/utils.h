/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:14:55 by acami             #+#    #+#             */
/*   Updated: 2021/07/30 15:05:02 by acami            ###   ########.fr       */
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

// Returns absolute value of an int64_t (Excluding INT64_MIN)
int64_t	myAbs(int64_t num);

// Returns the greater value from a and b
int64_t	myMax(int64_t a, int64_t b);

// Returns the lesser value from a and b
int64_t	myMin(int64_t a, int64_t b);

// Returns the value from a and b, which absolute value is greater
int64_t	myMaxAbs(int64_t a, int64_t b);

// Returns the value from a and b, which absolute value is lesser
int64_t	myMinAbs(int64_t a, int64_t b);

#endif