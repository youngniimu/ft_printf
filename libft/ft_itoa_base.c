/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:19:38 by thalme            #+#    #+#             */
/*   Updated: 2019/12/12 16:53:19 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(long long nb, int base)
{
	int			count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		count++;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		nb = nb / base;
		count++;
	}
	return (count);
}

char			*ft_itoa_base(long long nb, int base)
{
	long		i;
	int			count;
	char		*ret;
	int			c;

	i = nb;
	count = ft_len(i, base);
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
		ret[c] = i % base > 9 ? i % base + 87 : i % base + 48;
		i = i / base;
		c--;
	}
	return (ret);
}
