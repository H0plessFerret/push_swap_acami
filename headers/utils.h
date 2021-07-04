/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acami <acami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:14:55 by acami             #+#    #+#             */
/*   Updated: 2021/07/04 16:42:28 by acami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <inttypes.h>

// Malloc bytes_to_alloc bytes. Exits the programm if malloc returns NULL
void	*xMalloc(size_t bytes_to_alloc);

// Convert int64_t value to a string
char	*ft_ltoa(int64_t n);

// Convert string to int64_t value
int64_t	ft_atol(const char *str);

#endif