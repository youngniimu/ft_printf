/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:44:25 by thalme            #+#    #+#             */
/*   Updated: 2019/10/29 18:42:13 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*ret;
	size_t		i;

	i = 0;
	if (!(ret = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < (size + 1))
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}
