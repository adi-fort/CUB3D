/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:29:06 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/01/23 14:08:29 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (n < 0 && n != -2147483648)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n <= 9 && n > 0)
		ft_putchar_fd(n + 48, fd);
	else if (n > 0)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
}
