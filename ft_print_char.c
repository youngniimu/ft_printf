/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:42:52 by thalme            #+#    #+#             */
/*   Updated: 2020/01/20 16:22:44 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(va_list ap, t_tab *tab)
{
	char	*ret;
	char	c;

	if (tab->csp == 'c')
		c = va_arg(ap, int);
	else
		c = '%';
	if (tab->width == 0)
	{
		write(1, &c, 1);
		return (1);
	}
	ret = ft_memset(ft_strnew(tab->width - 1), tab->zero, tab->width - 1);
	if (tab->left_align == 0)
	{
		write(1, ret, tab->width - 1);
		write(1, &c, 1);
	}
	else
	{
		write(1, &c, 1);
		write(1, ret, tab->width - 1);
	}
	free(ret);
	return (tab->width);
}
