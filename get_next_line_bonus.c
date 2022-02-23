/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:55:57 by mprigent          #+#    #+#             */
/*   Updated: 2022/02/23 20:47:39 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char		*ft_line(char *save, char **line, int ret)
{
	size_t		i;
	char		*temp;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(save))
	{
		(*line) = ft_substr(save, 0, i);
		temp = ft_substr(save, i + 1, ft_strlen(save));
		free(save);
		save = ft_strdup(temp);
		free(temp);
	}
	else if (ret == 0)
	{
		(*line) = save;
		save = NULL;
	}
	return (save);
}

static char		*ft_save(char *buffer, char *save)
{
	char		*temp;

	if (save)
	{
		temp = ft_strjoin(save, buffer);
		save = ft_strdup(temp);
		free(temp);
	}
	else
		save = ft_strdup(buffer);
	return (save);
}

int				get_next_line(int fd, char **line)
{
	static char	*save[256];
	int			ret;
	char		buffer[BUFFER_SIZE + 1];

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buffer[ret] = '\0';
		save[fd] = ft_save(buffer, save[fd]);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (ret <= 0 && !save[fd])
	{
		(*line) = ft_strdup("");
		return (ret);
	}
	save[fd] = ft_line(save[fd], line, ret);
	if (ret <= 0 && !save[fd])
		return (ret);
	return (1);
}
