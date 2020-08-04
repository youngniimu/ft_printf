/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:57:35 by thalme            #+#    #+#             */
/*   Updated: 2019/12/16 12:24:49 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char		*ft_make_pointer(char *str)
{
	char	*temp;

	temp = ft_strjoin("0x", str);
	ft_strdel(&str);
	return (temp);
}

static char		*print_pointer(va_list ap, t_tab *tab)
{
	int			len;
	void		*ptr;
	char		*address;
	char		*str;
	char		*nb;

	ptr = va_arg(ap, void*);
	nb = ft_itoa((int)ptr);
	len = ft_strlen(nb) - 1;
	ft_strdel(&nb);
	address = ft_itoa_base((long long)ptr, 16);
	if (tab->precision != -1)
	{
		tab->precision = len > tab->precision ? len : tab->precision;
		str = ft_make_pointer(ft_handle_precision(tab, address));
		return (ft_choosepadding(tab, address));
	}
	return (ft_choosepadding(tab, ft_make_pointer(address)));
}

char			*print_string(va_list ap, t_tab *tab)
{
	char		*str;
	char		*ret;

	if (tab->csp == 'p')
		return (print_pointer(ap, tab));
	if (!(str = va_arg(ap, char*)))
		str = "(null)";
	ret = tab->precision != -1
	? ft_strndup(str, (tab->precision))
	: ft_strdup(str);
	return (ft_choosepadding(tab, ret));
}
