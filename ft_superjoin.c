/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_superjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:05:52 by thalme            #+#    #+#             */
/*   Updated: 2020/02/26 18:05:53 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_superjoin(int count, ...)
{
	va_list		op;
	char		*str;
	char		*temp;
	char		*arg;
	int			i;

	i = 1;
	va_start(op, count);
	str = va_arg(op, char*);
	while (i < count)
	{
		arg = va_arg(op, char*);
		temp = ft_strjoin(str, arg);
		free(str);
		str = ft_strndup(temp, ft_strlen(temp));
		free(temp);
		i++;
	}
	va_end(op);
	return (str);
}
