/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <dfiliagg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:30:57 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/06/20 14:56:22 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strncpyfrom(char *s, int n)
{
	int	i;
	int	j;

	i = n;
	j = 0;
	if (!s)
		return ;
	while (s[++i])
	{
		s[j] = s[i];
		j++;
	}
	s[j] = 0;
	return ;
}

char	*get(char *buf, int fd, int *rd)
{
	char		*line;
	char		*tmp;

	*rd = 1;
	line = ft_strdup2(buf);
	while (ft_strchr2(line, '\n') == -1 && *rd != 0)
	{
		*rd = read(fd, (void *)buf, BUFFER_SIZE);
		buf[*rd] = 0;
		tmp = line;
		line = ft_strjoin2(tmp, buf);
		free(tmp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	int			rd;
	static char	buf[BUFFER_SIZE];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	line = get(buf, fd, &rd);
	if (rd == 0)
	{
		if (!line)
		{
			free(line);
			return (0);
		}
		return (line);
	}
	line[ft_strchr2(line, '\n') + 1] = 0;
	ft_strncpyfrom(buf, ft_strchr2(buf, '\n'));
	return (line);
}
