/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:47:41 by thalme            #+#    #+#             */
/*   Updated: 2019/12/12 15:53:13 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char			*ft_add_f_hash(char *nb)
{
	char	*temp;

	temp = ft_strjoin(nb, ".");
	ft_strdel(&nb);
	return (temp);
}

char				*print_float(va_list ap, t_tab *tab)
{
	long double		double_nb;
	char			*nb;

	tab->precision += tab->precision == -1 ? 7 : 0;
	double_nb = tab->flag == 5 ? va_arg(ap, long double) : va_arg(ap, double);
	tab->negative = double_nb < 0 ? TRUE : FALSE;
	nb = ft_ftoa(double_nb, tab->precision);
	if (tab->precision == 0 && tab->hash)
		nb = ft_add_f_hash(nb);
	nb = ft_choosepadding(tab, nb);
	return (nb);
}
