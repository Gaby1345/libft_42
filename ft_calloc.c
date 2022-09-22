/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrabajo <gtrabajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:03:50 by gtrabajo          #+#    #+#             */
/*   Updated: 2022/09/22 17:27:39 by gtrabajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	arr = NULL;
	arr = malloc(size * count);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, (count * size));
	return (arr);
}
