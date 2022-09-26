/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabymb <gabymb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:15:17 by gabymb            #+#    #+#             */
/*   Updated: 2022/09/24 21:08:14 by gabymb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	free_matrix(char **mat, int n);
static int	counter(const char *s, char c);
static char	*get_word(const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		size;
	int		i;
	int		j;

	size = counter(s, c);
	arr = (char **)malloc((size + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	if (size == 0)
	{
		arr[0] = NULL;
		return (arr);
	}
	i = 0;
	j = 0;
	while (i < size && s[j])
	{
		while (s[j] == c)
			j++;
		arr[i] = get_word(&(s[j]), c);
		if (arr[i] == NULL)
		{
			free_matrix(arr, i);
			return (NULL);
		}
		while (s[j] != c && s[j])
			j++;
		i++;
	}
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

static char	*get_word(const char *s, char c)
{
	char	*word;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	word = (char *)malloc(((i + 1) * sizeof(char)));
	if (word == NULL)
		return (NULL);
	while (j < i)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
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
