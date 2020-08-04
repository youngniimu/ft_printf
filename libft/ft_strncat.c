/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:04:59 by thalme            #+#    #+#             */
/*   Updated: 2019/10/28 14:19:23 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *orig, const char *add, size_t len)
{
	size_t i;
	size_t j;

	i = ft_strlen(orig);
	j = 0;
	while (j < len && add[j])
	{
		orig[i + j] = add[j];
		j++;
	}
	orig[i + j] = '\0';
	return (orig);
}
