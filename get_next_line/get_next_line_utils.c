/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <dfiliagg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:30:57 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/06/20 14:56:22 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen2(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup2(char *s)
{
	int		i;
	char	*s2;

	if (!s)
		return (0);
	i = -1;
	s2 = malloc(ft_strlen2(s) + 1);
	while (s[++i])
		s2[i] = s[i];
	s2[i] = 0;
	return (s2);
}

char	*ft_strjoin2(char *s, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s || !s2)
		return (0);
	s3 = malloc(ft_strlen2(s) + ft_strlen2(s2) + 1);
	if (!s3)
		return (0);
	i = -1;
	j = -1;
	while (s[++i])
		s3[i] = s[i];
	while (s2[++j])
	{
		s3[i] = s2[j];
		i++;
	}
	s3[i] = 0;
	return (s3);
}

int	ft_strchr2(char *s, char c)
{
	int	i;

	i = -1;
	if (!s)
		return (-1);
	if (c == 0)
		return (ft_strlen2(s));
	while (s[++i])
	{
		if (s[i] == c)
			return (i);
	}
	return (-1);
}

char	*ft_strncpy(char *s, int n)
{
	int		i;
	char	*s2;

	i = -1;
	if (!s)
		return (0);
	s2 = malloc(n + 1);
	if (!s2)
		return (0);
	while (s[++i] || i < n)
	{
		s2[i] = s[i];
	}
	s2[i] = 0;
	return (s2);
}
