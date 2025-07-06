/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:21:16 by hanjkim           #+#    #+#             */
/*   Updated: 2024/07/01 14:47:13 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (str == NULL)
		return (count);
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(const char *str, int c)
{
	while (str && *str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	int		index;
	int		len;
	char	*dup;

	if (str == NULL)
		return (NULL);
	index = 0;
	len = ft_strlen(str);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (index < len)
	{
		dup[index] = str[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*newstr;
	size_t	index1;
	size_t	index2;
	size_t	len;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	len = ft_strlen(str1) + ft_strlen(str2);
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	index1 = 0;
	index2 = 0;
	while (str1 && str1[index1])
	{
		newstr[index1] = str1[index1];
		index1++;
	}
	while (str2 && str2[index2])
	{
		newstr[index1 + index2] = str2[index2];
		index2++;
	}
	newstr[index1 + index2] = '\0';
	return (newstr);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*newsubstr;
	size_t	index;

	if (str == NULL)
		return (NULL);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	newsubstr = (char *)malloc(sizeof(char) * (len + 1));
	if (newsubstr == NULL)
		return (NULL);
	index = 0;
	while (str[start + index] && index < len)
	{
		newsubstr[index] = str[start + index];
		index++;
	}
	newsubstr[index] = '\0';
	return (newsubstr);
}
