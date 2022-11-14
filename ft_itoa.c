/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrabajo <gtrabajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:13:34 by gtrabajo          #+#    #+#             */
/*   Updated: 2022/11/14 19:25:00 by gtrabajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	number_size(long n);

char	*ft_itoa(int n)
{
	char	*str;
	int		index;
	int		size;

	index = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = number_size((long)n);
	str = (char *)ft_calloc((size + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[index] = '-';
		n = n * (-1);
	}
	while ((str[0] == '-' && size > 1) || (str[0] != '-' && size >= 1))
	{
		str[size - 1] = (n % 10) + 48;
		n = n / 10;
		size--;
	}
	return (str);
}

static int	number_size(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
