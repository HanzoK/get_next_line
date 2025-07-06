/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:21:12 by hanjkim           #+#    #+#             */
/*   Updated: 2025/05/26 18:56:36 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE > 10000
# error "BUFFER_SIZE must be less than or equal to 10000"
# endif


size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif
