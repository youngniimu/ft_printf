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

#include "ft_printf.h"

int			print_string(va_list ap, t_tab *tab)
{
	char	*str;

	if (tab->csp == 's')
		str = va_arg(ap, char*);
	else
		str = ft_itoa_base(va_arg(ap, long long), 16);
	if (str == NULL)
	{
		str = ft_strnew(6);
		str = "(null)";
	}
	if (tab->csp == 'p')
		str = ft_strjoin("0x", str);
	str = ft_strndup(str, (tab->precision));
	str = ft_choosepadding(tab, str, 0);
	ft_putstr(str);
	free(str);
	return (ft_strlen(str));
}
