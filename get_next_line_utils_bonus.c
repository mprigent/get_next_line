/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:00:44 by mprigent          #+#    #+#             */
/*   Updated: 2022/02/23 20:48:18 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	size_t	i;

	i = 0;
	if (!(cpy = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		y;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	y = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[y] != '\0')
	{
		new[i + y] = s2[y];
		y++;
	}
	free(s1);
	new[i + y] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (s_len < start)
	{
		while (i++ < len)
			new[i] = '\0';
	}
	while (i < len && s[start + i] != '\0')
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	char *cs;

	cs = (char *)s;
	if (*cs == (char)c)
		return (cs);
	while (*cs++)
	{
		if (*cs == (char)c)
			return (cs);
	}
	if ((char)c == '\0')
		return (cs);
	return (NULL);
}
