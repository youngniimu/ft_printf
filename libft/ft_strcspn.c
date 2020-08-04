/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 09:51:13 by thalme            #+#    #+#             */
/*   Updated: 2019/12/09 10:04:42 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strcspn(const char *s, const char *charset)
{
	size_t i;
	size_t j;

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (charset[++j])
			if (s[i] == charset[j])
				return (i);
	}
	return (i);
}
