/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:56:32 by thalme            #+#    #+#             */
/*   Updated: 2019/10/28 12:04:50 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *orig, const char *add)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (orig[i])
		i++;
	while (add[j])
	{
		orig[i] = add[j];
		i++;
		j++;
	}
	orig[i] = '\0';
	return (orig);
}
