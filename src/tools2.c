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

#include "../include/ft_printf.h"

long long			ft_select_type_signed(va_list ap, t_tab *tab)
{
	intmax_t		n;

	n = 0;
	if (tab->flag == 1)
		n = (signed char)va_arg(ap, intmax_t);
	else if (tab->flag == 2)
		n = (short int)va_arg(ap, intmax_t);
	else if (tab->flag == 3)
		n = (long long int)va_arg(ap, intmax_t);
	else if (tab->flag == 4)
		n = (long int)va_arg(ap, intmax_t);
	else
		n = va_arg(ap, int);
	return (n);
}

unsigned long long	ft_select_type_unsigned(va_list ap, t_tab *tab)
{
	uintmax_t		n;

	n = 0;
	if (tab->flag == 1)
		n = (unsigned char)va_arg(ap, uintmax_t);
	else if (tab->flag == 2)
		n = (unsigned short int)va_arg(ap, uintmax_t);
	else if (tab->flag == 3)
		n = (unsigned long long int)va_arg(ap, uintmax_t);
	else if (tab->flag == 4)
		n = (unsigned long int)va_arg(ap, uintmax_t);
	else
		n = (unsigned int)va_arg(ap, uintmax_t);
	return (n);
}

static char			*ft_sign(char *sign, char *str)
{
	char			*ret;

	ret = ft_strjoin(sign, str);
	ft_strdel(&str);
	str = ft_strndup(ret, ft_strlen(ret));
	ft_strdel(&ret);
	return (str);
}

char				*ft_addsign(char *str, t_tab *tab)
{
	if (tab->plus == 1 && !tab->negative && tab->csp != 'u')
		str = ft_sign("+", str);
	if (tab->empty == 1 && !tab->negative && !tab->plus && tab->csp != 'u')
		str = ft_sign(" ", str);
	if (tab->negative && str[0] != '-')
		str = ft_sign("-", str);
	if (tab->hash == 1 && tab->csp != 'f' && str[0] != '0')
		str = ft_sign("0", str);
	if (tab->hash == 2 && tab->precision != 0 && str[0] != '\0')
		str = ft_sign("0x", str);
	return (str);
}
