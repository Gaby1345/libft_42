/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrabajo <gtrabajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:15:17 by gabymb            #+#    #+#             */
/*   Updated: 2022/11/15 19:49:58 by gtrabajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	counter(const char *s, char c);
static int	*words_size(const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		*words;
	int		size;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	words = words_size(s, c);
	size = counter(s, c);
	printf("WORDS: %d", words[0]);
	printf("SIZE: %d", size);
	arr = (char **)malloc((size + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		arr[i] = ft_substr(s, j, words[i]);
		j = words[i];
		i++;
	}
	arr[i] = NULL;
	free(words);
	return (arr);
}

static int	counter(const char *s, char c)
{
	int		n;
	int		flag;

	n = 0;
	flag = 0;
	if (*s == 0)
		return (0);
	while (*s)
	{
		if (*s == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			n++;
		}	
		s++;
	}
	return (n);
}

static int	*words_size(const char *s, char c)
{
	int	*words;
	int	letters;
	int	i;

	letters = 0;
	i = 0;
	words = (int *)malloc(counter(s, c) * sizeof(int));
	if (words == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == c)
		{
			words[i] = letters - 1;
			letters = 0;
		}
		letters++;
		s++;
	}
	return (words);
}
