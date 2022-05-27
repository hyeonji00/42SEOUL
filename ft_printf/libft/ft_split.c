/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjik <hyeonjik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:13:39 by hyeonjik          #+#    #+#             */
/*   Updated: 2022/05/07 13:33:53 by hyeonjik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			cnt++;
		}
		else
			i++;
	}
	return (cnt);
}

static char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**ft_all_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != (void *)0)
		free(arr[i++]);
	free(arr);
	return (0);
}

static char	**ft_return_split(char const *s, char c, int i, int j)
{
	char	**arr;
	int		idx;

	arr = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (arr == 0)
		return (0);
	idx = 0;
	while (s[i] != '\0')
	{
		j = i;
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			arr[idx] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			if (arr[idx] == 0)
				return (ft_all_free(arr));
			ft_strncpy(arr[idx++], (char *)s + j, i - j);
		}
		else
			i++;
	}
	arr[idx] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**arr;

	if (s == 0)
		return (0);
	i = 0;
	j = i;
	arr = ft_return_split(s, c, i, j);
	return (arr);
}
