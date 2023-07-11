/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <dfiliagg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:30:57 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/06/20 14:56:22 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 1

char	*ft_strdup2(char *s);
int		ft_strlen2(char *s);
char	*ft_strjoin2(char *s, char *s2);
int		ft_strchr2(char *s, char c);
void	ft_strncpyfrom(char *s, int n);
char	*ft_strncpy(char *s, int n);
char	*get_next_line(int fd);

#endif