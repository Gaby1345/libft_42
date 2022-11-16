/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrabajo <gtrabajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:15:17 by gabymb            #+#    #+#             */
/*   Updated: 2022/11/16 16:14:01 by gtrabajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	counter(const char *s, char c)
{
	int		n;
	int		flag;

	n = 0;
	flag = 0;
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

static int	count_letters(const char *s, char c, int index)
{
	int	letters;

	letters = 0;
	while (s[index] == c)
		index++;
	while (s[index] != c)
	{
		index++;
		letters++;
	}
	return (letters);
}

static void	free_matrix(char **mat, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

char	*get_word(char const *s, char c, int *index)
{
	int		i;
	int		j;
	int		len;
	char	*word;

	i = *index;
	j = 0;
	len = count_letters(s, c, i);
	word = (char *)malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	while (s[i] == c)
		i++;
	while (s[i] != c)
	{
		word[j] = s[i];
		i++;
		j++;
	}
	word[j++] = '\0';
	*index = i;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**arr;
	int		wordn;
	int		i;
	int		index;

	if (s == 0)
		return (NULL);
	i = 0;
	index = 0;
	str = ft_strtrim(s, &c);
	wordn = counter(str, c);
	arr = (char **)ft_calloc((wordn + 1), sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (i < wordn)
	{
		arr[i] = get_word(str, c, &index);
		if (arr[i] == NULL)
			free_matrix(arr, i);
		i++;
	}
	return (arr);
}
