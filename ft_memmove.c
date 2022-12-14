/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabymb <gabymb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:08:37 by gabymb            #+#    #+#             */
/*   Updated: 2022/12/14 19:21:50 by gabymb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*auxd;
	unsigned char	*auxs;

	auxd = (unsigned char *)dst;
	auxs = (unsigned char *)src;
	if (!auxd && !auxs)
		return (NULL);
	if (auxd < auxs)
		while (len--)
			*auxd++ = *auxs++;
	else
		while (len--)
			*(auxd + len) = *(auxs + len);
	return (dst);
}
