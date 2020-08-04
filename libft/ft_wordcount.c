/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 10:59:06 by thalme            #+#    #+#             */
/*   Updated: 2019/10/30 11:03:43 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wordcount(char const *s, char c)
{
	size_t	words;
	size_t	i;
	size_t	end;

	i = 0;
	words = 0;
	end = ft_strlen(s);
	end--;
	while (s[end] == c && end > 0)
		end--;
	while (i < end)
	{
		while (s[i] == c && i <= end)
			i++;
		if (s[i] != c && s[i] != '\0')
			words++;
		while (s[i] != c && i <= end)
			i++;
	}
	return (words);
}
