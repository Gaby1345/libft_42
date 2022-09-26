/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabymb <gabymb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:43:57 by gabymb            #+#    #+#             */
/*   Updated: 2022/09/24 18:38:07 by gabymb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		size;

	i = 1;
	j = 0;
	size = ft_strlen(s1);
	str = (char *)malloc(size * sizeof(char));
	if (str == NULL)
		return (NULL);
	size--;
	while (set[i++])
	{
		if (s1[j] != set[i] && s1[size] != set[i])
		{
			ft_strlcpy(str, (s1 + j), size - j);
			break ;
		}
		while (s1[j] == set[i])
			j++;
		while (s1[size] == set[i])
			size--;
	}
	return (str);
}
