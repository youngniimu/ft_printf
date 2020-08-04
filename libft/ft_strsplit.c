/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 09:35:05 by thalme            #+#    #+#             */
/*   Updated: 2019/11/06 16:10:48 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_copy(char **ret, char const *s, char c, size_t words)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < words)
	{
		k = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			ret[j][k++] = s[i++];
		ret[j][k] = '\0';
		j++;
	}
	ret[j] = NULL;
	return (ret);
}

static char		**ft_allocatemem(char **ret, char const *s, char c, size_t w)
{
	size_t	i;
	size_t	j;
	size_t	letters;

	j = 0;
	i = 0;
	if (s[i] == '\0')
		if (!(ret[j] = (char*)malloc(sizeof(char))))
			return (NULL);
	while (s[i] && j < w)
	{
		letters = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			letters++;
			i++;
		}
		if (!(ret[j++] = (char*)malloc(sizeof(char) * (letters + 1))))
			return (NULL);
	}
	return (ret);
}

static size_t	ft_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i] != '\0')
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	size_t	words;

	words = ft_words(s, c);
	if (!(ret = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	if (!(ret = ft_allocatemem(ret, s, c, words)))
		return (NULL);
	ret = ft_copy(ret, s, c, words);
	return (ret);
}
