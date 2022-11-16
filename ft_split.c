/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrabajo <gtrabajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:15:17 by gabymb            #+#    #+#             */
/*   Updated: 2022/11/16 15:18:24 by gtrabajo         ###   ########.fr       */
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

char	*get_word(char *s, char c, int *index)
{
	int		i;
	int		j;
	char	*word;

	i = (*index);
	while (s[i] == c)
		i++;
	j = i;
	while (s[j] != c)
		j++;
	(*index) = j;
	word = ft_substr(s, i, j - i);
	if (word == NULL)
		return (NULL);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**arr;
	int		wordn;
	int		i;
	int		index;

	if (s == NULL)
		return (NULL);
	i = 0;
	index = 0;
	str = ft_strtrim(s, &c);
	wordn = counter(str, c);
	printf("wordn = %d\n", wordn);
	arr = (char **)ft_calloc(wordn + 1, sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (i < wordn)
	{
		arr[i] = get_word(str, c, &index);
		if (arr[i] == NULL)
		{
			free_matrix(arr, i);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

int	main()
{
	char		**matrix;
	int			i = 0;

	matrix = ft_split("    Hola    buenas    ", ' ');
	while (matrix[i])
	{
		printf("%i - %s\n", i , matrix[i]);
		i++;
	}
	return (0);
}
