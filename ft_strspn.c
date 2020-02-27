/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:02:43 by thalme            #+#    #+#             */
/*   Updated: 2019/12/09 09:48:43 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strspn(const char *s, const char *charset)
{
	size_t i;
	size_t j;
	size_t count;

	i = -1;
	while (s[++i])
	{
		j = -1;
		count = 0;
		while (charset[++j])
			count += s[i] == charset[j] ? 1 : 0;
		if (count == 0)
			return (i);
	}
	return (i);
}
