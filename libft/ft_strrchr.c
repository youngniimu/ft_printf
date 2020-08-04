/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:26:37 by thalme            #+#    #+#             */
/*   Updated: 2019/10/28 15:14:21 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int i)
{
	size_t	c;

	c = ft_strlen((char*)s);
	while (c > 0)
	{
		if (s[c] == i)
			return ((char*)s + c);
		c--;
	}
	if (s[c] == i)
		return ((char*)s + c);
	return (NULL);
}
