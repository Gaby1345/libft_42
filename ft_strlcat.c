/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabymb <gabymb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:56:43 by gabymb            #+#    #+#             */
/*   Updated: 2022/09/20 14:30:19 by gabymb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{	
	size_t	dsize;
	size_t	ssize;

	dsize = 0;
	ssize = ft_strlen(src);
	while (*dst && dstsize > 0)
	{
		dsize++;
		dst++;
		dstsize--;
	}
	while (*src && (dstsize-- > 1))
	{
		*dst = *src;
		dst++;
		src++;
	}
	if (dstsize == 0 || *src == '\0')
		*dst = '\0';
	return (dsize + ssize);
}
