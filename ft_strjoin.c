/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 09:30:39 by thalme            #+#    #+#             */
/*   Updated: 2019/10/31 09:06:10 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;

	j = ft_strlen(s1);
	i = j + ft_strlen(s2);
	if (!(ret = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
	{
		ret[j] = s1[j];
		j++;
	}
	while (s2[i] != '\0')
	{
		ret[i + j] = s2[i];
		i++;
	}
	ret[i + j] = '\0';
	return (ret);
}
