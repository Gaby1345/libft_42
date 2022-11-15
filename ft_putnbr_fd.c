/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabymb <gabymb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:57:32 by gtrabajo          #+#    #+#             */
/*   Updated: 2022/11/15 14:04:03 by gabymb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	printing(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	int	recursiven;

	if (n < 0 && n != -2147483648)
	{
		n = -n;
		write(fd, "-", 1);
		ft_putnbr_fd(n, fd);
		return ;
	}
	if (n >= 0 && n <= 9)
		printing(n, fd);
	else if (n == -2147483648)
	{
		write (fd, "-", 1);
		write (fd, "2147483648", 10);
	}
	else
	{
		recursiven = n % 10;
		ft_putnbr_fd(((n - recursiven) / 10), fd);
		printing(recursiven, fd);
	}
	return ;
}

void	printing(int n, int fd)
{
	char	c;

	c = n + '0';
	write(fd, &c, 1);
	return ;
}
