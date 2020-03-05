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

static char	*ft_make_pointer(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s2);
	return (temp);
}

int			print_string(va_list ap, t_tab *tab)
{
	char	*str;

	if (tab->csp == 's')
	{
		if (!(str = va_arg(ap, char*)))
			str = "(null)";
	}
	else
		str = ft_make_pointer("0x", (ft_itoa_base(va_arg(ap, long long), 16)));
	if (tab->csp == 's')
		str = ft_strndup(str, (tab->precision));
	str = ft_choosepadding(tab, str, 0);
	ft_putstr(str);
	return (ft_strlen(str));
}
