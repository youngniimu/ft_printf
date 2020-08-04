/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 14:43:57 by thalme            #+#    #+#             */
/*   Updated: 2020/07/31 14:43:58 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		ft_set_exceptions(t_tab *tab)
{
	if (tab->left_align)
		tab->padding_type = ' ';
	if (tab->csp == 'X' || tab->csp == 'x' ||
		tab->csp == 'o' || tab->csp == 'p')
	{
		tab->plus = FALSE;
		tab->empty = FALSE;
	}
}

static void		ft_star_precision(t_ptr *ptr, t_tab *tab)
{
	int			arg;

	arg = va_arg(ptr->ap, int);
	if (arg >= 0)
		tab->precision = arg;
	else
		tab->precision = -1;
}

static void		ft_star_width(t_ptr *ptr, t_tab *tab)
{
	int			arg;

	arg = va_arg(ptr->ap, int);
	tab->left_align = arg >= 0 && !tab->left_align ? 0 : 1;
	tab->width = (ft_abs(arg));
}

static void		ft_set_length_flag(t_tab *tab, const char *csp, size_t len)
{
	tab->flag = 0;
	if (csp[len - 2] == 'h' && csp[len - 3] == 'h')
		tab->flag = 1;
	else if (csp[len - 2] == 'h' && csp[len - 3] != 'h')
		tab->flag = 2;
	else if (csp[len - 2] == 'l' && csp[len - 3] == 'l')
		tab->flag = 3;
	else if (csp[len - 2] == 'l' && csp[len - 3] != 'l')
		tab->flag = 4;
	else if (csp[len - 2] == 'L')
		tab->flag = 5;
}

void			ft_setflags(t_tab *tab, const char *csp, size_t len, t_ptr *ptr)
{
	tab->csp = csp[len - 1];
	tab->is_null = FALSE;
	tab->negative = FALSE;
	tab->roundup = FALSE;
	tab->width = ft_atoi(&csp[ft_strspn(csp, "+-0 #%")]);
	tab->precision = ft_strchr(csp, '.')
	? ft_atoi(&csp[ft_strcspn(csp, ".") + 1])
	: -1;
	tab->plus = ft_strchr(csp, '+') ? TRUE : FALSE;
	tab->empty = ft_strchr(csp, 32) ? TRUE : FALSE;
	tab->hash = ft_strchr(csp, '#') ? TRUE : FALSE;
	tab->left_align = ft_strchr(csp, '-') ? TRUE : FALSE;
	tab->padding_type = ft_strnchr(csp, '0', ft_strcspn(csp, "0123456789"))
	? '0'
	: ' ';
	ft_set_length_flag(tab, csp, len);
	ft_set_exceptions(tab);
	if (ft_strchr(csp, '*') && (*(ft_strchr(csp, '*') - 1) != '.'))
		ft_star_width(ptr, tab);
	if (ft_strstr(csp, ".*"))
		ft_star_precision(ptr, tab);
}
