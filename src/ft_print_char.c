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

#include "../include/ft_printf.h"

char		*print_char(va_list ap, t_tab *tab)
{
	char	*ret;
	char	c;

	if (tab->csp == 'c')
		c = va_arg(ap, int);
	else
		c = '%';
	if (c == 0 && !tab->width)
		tab->is_null = 1;
	if (!tab->width)
		return (ft_memset(ft_strnew(1), c, 1));
	ret = ft_memset(ft_strnew(tab->width), tab->padding_type, tab->width);
	if (!tab->left_align)
		ft_memset(&ret[tab->width - 1], c, 1);
	else
		ft_memset(ret, c, 1);
	return (ret);
}
