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

#include "ft_printf.h"

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

static char		*ft_capital(char *nb)
{
	int i;

	i = -1;
	while (nb[++i])
		nb[i] = ft_toupper(nb[i]);
	return (nb);
}

char				*print_base(va_list ap, t_tab *tab)
{
	char		*nb;
	long long	i;
	size_t		negative;

	if (tab->csp == 'x' || tab->csp == 'X')
		tab->hash += tab->hash == 1 ? 1 : 0;
	i = ft_select_type(ap, tab);
	if (i == -9223372036854775807 - 1)
		return ("-9223372036854775808");
	negative = i < 0 ? 1 : 0;
	i *= i < 0 ? -1 : 1;
	nb = ft_itoa_base(i, ft_choose_base(tab));
	if (tab->precision == 0 && nb[0] == '0')
		nb[0] = '\0';
	tab->hash *= nb[0] != '0' ? 1 : 0;
	if (tab->precision > (int)ft_strlen(nb))
		nb = ft_handle_precision(tab, nb);
	if (tab->precision != -1)
		tab->zero = ' ';
	nb = ft_choosepadding(tab, nb, negative);
	if (tab->csp == 'X')
		nb = ft_capital(nb);
	return (nb);
}
