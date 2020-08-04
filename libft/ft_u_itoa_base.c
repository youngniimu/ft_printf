/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:19:38 by thalme            #+#    #+#             */
/*   Updated: 2019/12/12 16:53:19 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_u_itoa_base(unsigned long long nb, int base)
{
	int		i;
	char	*arr;
	char	*bases;

	if (base > 16 || base < 1)
		return (NULL);
	bases = "0123456789abcdef";
	if (!(arr = ft_strnew(ft_numlen_base(nb, base))))
		return (NULL);
	if (nb == 0)
		arr[0] = '0';
	i = 0;
	while (nb != 0)
	{
		arr[i++] = bases[nb % base];
		nb = nb / base;
	}
	ft_strrev(arr);
	return (arr);
}
