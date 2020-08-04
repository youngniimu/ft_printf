/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:55:33 by thalme            #+#    #+#             */
/*   Updated: 2019/11/02 10:51:10 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	if (!dest && !src)
		return (dest);
	i = 0;
	if (dest < src)
	{
		while (i < len)
		{
			*(unsigned char*)(dest + i) = *(unsigned char*)(src + i);
			i++;
		}
	}
	else
	{
		i = len;
		while (i-- > 0)
			*(unsigned char*)(dest + i) = *(unsigned char*)(src + i);
	}
	return (dest);
}
