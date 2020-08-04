/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:08:28 by thalme            #+#    #+#             */
/*   Updated: 2019/10/24 12:04:34 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle)
		return ((char*)hay);
	while (hay[i] || i < len)
	{
		j = 0;
		while ((hay[j + i] == needle[j] && (i + j) <= len) || needle[j] == '\0')
		{
			if (needle[j] == '\0')
				return ((char*)hay + i);
			j++;
			if (j + i > len)
				return (NULL);
		}
		i++;
	}
	return (NULL);
}
