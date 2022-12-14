/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabymb <gabymb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:15:17 by gabymb            #+#    #+#             */
/*   Updated: 2022/12/14 18:29:22 by gabymb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	words_counter(const char *str, char c)
{
	int	counter;
	int	flag;

	counter = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			counter++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (counter);
}

static char	*words_filler(const char *str, int first, int last)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((last - first + 1) * sizeof(char));
	while (first < last)
		word[i++] = str[first++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		first;
	char	**mtrx;
	size_t	i;
	size_t	j;

	first = -1;
	i = 0;
	j = 0;
	mtrx = ft_calloc((words_counter(s, c) + 1), sizeof(char *));
	if (s == NULL || mtrx == NULL)
		return (NULL);
	while (i <= (size_t)ft_strlen(s))
	{
		if (s[i] != c && first < 0)
			first = i;
		else if ((s[i] == c || i == (size_t)ft_strlen(s)) && first >= 0)
		{
			mtrx[j++] = words_filler(s, first, i);
			first = -1;
		}
		i++;
	}
	mtrx[j] = NULL;
	return (mtrx);
}
