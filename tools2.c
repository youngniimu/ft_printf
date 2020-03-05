/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:05:01 by thalme            #+#    #+#             */
/*   Updated: 2020/02/26 11:05:06 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_select_type_unsigned(va_list ap, t_tab *tab)
{
	intmax_t n;

	n = 0;
	if (tab->flag == 1)
		n = (unsigned char)va_arg(ap, intmax_t);
	else if (tab->flag == 2)
		n = (unsigned short int)va_arg(ap, intmax_t);
	else if (tab->flag == 3)
		n = (unsigned long long int)va_arg(ap, intmax_t);
	else if (tab->flag == 4)
		n = (unsigned long int)va_arg(ap, intmax_t);
	else
		n = (unsigned int)va_arg(ap, intmax_t);
	return (n);
}

char				*ft_handle_precision(t_tab *tab, char *nb)
{
	char			*pad;

	pad = ft_memset(ft_strnew(tab->precision), '0', tab->precision);
	ft_memcpy(&pad[tab->precision - (ft_strlen(nb))], nb, ft_strlen(nb));
	free(nb);
	return (pad);
}

static char			*ft_sign(char *sign, char *str)
{
	char			*ret;

	ret = ft_strjoin(sign, str);
	free(str);
	str = ft_strndup(ret, ft_strlen(ret));
	free(ret);
	return (str);
}

char				*ft_addpme(char *str, t_tab *tab, size_t neg)
{
	if (tab->plus == 1 && neg == 0 && tab->csp != 'u')
		str = ft_sign("+", str);
	if (tab->empty == 1 && neg == 0 && tab->plus == 0 && tab->csp != 'u')
		str = ft_sign(" ", str);
	if (neg == 1 && str[0] != '-')
		str = ft_sign("-", str);
	if (tab->hash == 1 && tab->csp != 'f' && str[0] != '0')
		str = ft_sign("0", str);
	if (tab->hash == 2 && tab->precision != 0 && str[0] != '\0')
		str = ft_sign("0x", str);
	return (str);
}
