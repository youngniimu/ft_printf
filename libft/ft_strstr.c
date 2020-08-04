/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:49:33 by thalme            #+#    #+#             */
/*   Updated: 2019/10/29 15:21:51 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *ndle)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ndle[i] == '\0')
		return ((char*)hay);
	while (hay[i])
	{
		j = 0;
		while (hay[j + i] == ndle[j])
		{
			j++;
			if (ndle[j] == '\0')
				return ((char*)hay + i);
		}
		i++;
	}
	return (NULL);
}
