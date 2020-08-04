/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:19:38 by thalme            #+#    #+#             */
/*   Updated: 2019/11/06 16:09:46 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(long nb)
{
	int count;

	if (nb == 0)
		return (1);
	count = 0;
	if (nb < 0)
	{
		count++;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int nb)
{
	long	i;
	int		count;
	char	*ret;
	int		c;

	i = nb;
	count = ft_len(i);
	if (!(ret = (char*)malloc(sizeof(char) * count + 1)))
		return (NULL);
	c = count;
	count = 0;
	if (i < 0)
	{
		ret[count++] = '-';
		i = i * -1;
	}
	ret[c--] = '\0';
	while (c >= count)
	{
		ret[c] = i % 10 + 48;
		i = i / 10;
		c--;
	}
	return (ret);
}
