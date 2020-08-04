/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:57:32 by thalme            #+#    #+#             */
/*   Updated: 2020/07/30 10:57:33 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		ft_powl(long double nb, int pow)
{
	int			i;
	long double	res;

	i = 0;
	res = 1;
	while (i < ft_abs(pow))
	{
		if (pow < 0)
			res = res * 1 / 10;
		else
			res = res * nb;
		i++;
	}
	return (res);
}
