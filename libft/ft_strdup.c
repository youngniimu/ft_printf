/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:31:05 by thalme            #+#    #+#             */
/*   Updated: 2019/10/29 18:55:09 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;

	len = (size_t)ft_strlen(s1);
	dup = (char*)ft_memalloc(len + 1);
	if (dup)
	{
		dup = ft_memcpy(dup, s1, len + 1);
		dup[len] = '\0';
	}
	return (dup);
}
