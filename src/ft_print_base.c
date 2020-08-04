/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsignedint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:02:54 by thalme            #+#    #+#             */
/*   Updated: 2019/12/16 16:37:23 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int		ft_choose_base(t_tab *tab)
{
	if (tab->csp == 'o')
		return (8);
	else if (tab->csp == 'x' || tab->csp == 'X')
		return (16);
	return (10);
}

static intmax_t	ft_select_type(va_list ap, t_tab *tab)
{
	if (tab->csp == 'd' || tab->csp == 'i')
		return (ft_select_type_signed(ap, tab));
	else
		return (ft_select_type_unsigned(ap, tab));
}

char			*print_unsigned_base(va_list ap, t_tab *tab)
{
	char		*nb;
	uintmax_t	i;

	if (tab->csp == 'x' || tab->csp == 'X')
		tab->hash += tab->hash == 1 ? TRUE : FALSE;
	i = ft_select_type(ap, tab);
	nb = ft_u_itoa_base(i, ft_choose_base(tab));
	if (tab->precision == 0 && nb[0] == '0')
		nb[0] = '\0';
	tab->hash *= nb[0] != '0' ? TRUE : FALSE;
	if (tab->precision > (int)ft_strlen(nb))
		nb = ft_handle_precision(tab, nb);
	if (tab->precision != -1)
		tab->padding_type = ' ';
	nb = ft_choosepadding(tab, nb);
	if (tab->csp == 'X')
		nb = ft_str_toupper(nb);
	return (nb);
}

static char		*print_signed_base(va_list ap, t_tab *tab)
{
	char		*nb;
	long long	base_nb;

	base_nb = ft_select_type(ap, tab);
	if (base_nb == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	tab->negative = base_nb < 0 ? TRUE : FALSE;
	base_nb *= base_nb < 0 ? -1 : 1;
	nb = ft_itoa_base(base_nb, ft_choose_base(tab));
	if (tab->precision == 0 && nb[0] == '0')
		nb[0] = '\0';
	tab->hash *= nb[0] != '0' ? TRUE : FALSE;
	if (tab->precision > (int)ft_strlen(nb))
		nb = ft_handle_precision(tab, nb);
	if (tab->precision != -1)
		tab->padding_type = ' ';
	nb = ft_choosepadding(tab, nb);
	if (tab->csp == 'X')
		nb = ft_str_toupper(nb);
	return (nb);
}

char			*print_base(va_list ap, t_tab *tab)
{
	if (tab->csp == 'd' || tab->csp == 'i')
		return (print_signed_base(ap, tab));
	return (print_unsigned_base(ap, tab));
}
