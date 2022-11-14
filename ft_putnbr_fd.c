/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrabajo <gtrabajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:57:32 by gtrabajo          #+#    #+#             */
/*   Updated: 2022/11/14 20:18:51 by gtrabajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	str = ft_itoa(n);
	if (str != NULL)
	{
		write(fd, str, ft_strlen(str));
		free(str);
	}
}


/**************************************/
void	printing(int n);

void	ft_putnbr(int nb)
{
	int	recursiven;

	if (nb < 0 && nb != -2147483648)
	{
		nb = -nb;
		write(1, "-", 1);
		ft_putnbr(nb);
		return ;
	}
	if (nb >= 0 && nb <= 9)
		printing(nb);
	else if (nb == -2147483648)
	{
		write (1, "-", 1);
		write (1, "2147483648", 10);
	}
	else
	{
		recursiven = nb % 10;
		ft_putnbr((nb - recursiven) / 10);
		printing(recursiven);
	}
	return ;
}

void	printing(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
	return ;
}