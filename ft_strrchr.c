/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabymb <gabymb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:14:56 by gabymb            #+#    #+#             */
/*   Updated: 2022/12/14 18:15:53 by gabymb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	*auxs;

	auxs = (unsigned char *)s;
	len = ft_strlen((const char *)auxs);
	while (len >= 0)
	{
		if (*(auxs + len) == (unsigned char)c)
			return ((char *)(auxs + len));
		len--;
	}
	return (NULL);
}
