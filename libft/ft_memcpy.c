/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:10:34 by thalme            #+#    #+#             */
/*   Updated: 2019/11/02 10:47:38 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*destcpy;
	const char	*srccpy;

	if (src == NULL && dst == NULL)
		return (NULL);
	destcpy = dst;
	srccpy = src;
	while (n--)
		*destcpy++ = *srccpy++;
	return (dst);
}
