/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 09:31:00 by thalme            #+#    #+#             */
/*   Updated: 2019/10/31 09:33:50 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*ret;
	size_t		i;
	size_t		start;
	size_t		end;

	i = ft_strlen(s);
	i--;
	start = 0;
	end = i;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end > start)
		end--;
	if (!(ret = (char*)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	i = 0;
	if (s[0] == '\0')
	{
		ret[0] = '\0';
		return (ret);
	}
	while (start <= end)
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}
