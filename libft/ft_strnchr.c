/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:13:23 by thalme            #+#    #+#             */
/*   Updated: 2019/12/09 19:02:08 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (s[i] && i < len)
	{
		if (s[i] == c)
			return ((char*)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char*)s + i);
	return (NULL);
}
