/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:23:26 by thalme            #+#    #+#             */
/*   Updated: 2019/12/16 16:23:26 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*ft_handle_precision(t_tab *tab, char *nb)
{
	char	*pad;

	pad = ft_memset(ft_strnew(tab->precision), '0', tab->precision);
	ft_memcpy(&pad[tab->precision - (ft_strlen(nb))], nb, ft_strlen(nb));
	ft_strdel(&nb);
	return (pad);
}

char		*ft_choosepadding(t_tab *tab, char *nb)
{
	if (ft_strlen(nb) < tab->width)
	{
		return (tab->padding_type == '0'
				? ft_zeropadding(tab, nb)
				: ft_emptypadding(tab, nb));
	}
	else
		return (ft_addsign(nb, tab));
}

static int	ft_adjust_width(t_tab *tab)
{
	tab->empty *= tab->plus ? FALSE : TRUE;
	tab->empty *= tab->negative ? FALSE : TRUE;
	tab->plus *= tab->negative ? FALSE : TRUE;
	return (tab->width - tab->plus - tab->empty - tab->negative - tab->hash);
}

char		*ft_zeropadding(t_tab *tab, char *nb)
{
	char	*pad;
	size_t	padlen;

	if (tab->csp == 'o' && tab->hash && tab->width >= ft_strlen(nb))
		tab->hash = 0;
	padlen = ft_adjust_width(tab);
	pad = ft_memset(ft_strnew(padlen), '0', padlen);
	if (!tab->left_align)
		ft_memcpy(&pad[padlen - (ft_strlen(nb))], nb, ft_strlen(nb));
	else
		ft_memcpy(pad, nb, (ft_strlen(nb)));
	pad = ft_addsign(pad, tab);
	ft_strdel(&nb);
	return (pad);
}

char		*ft_emptypadding(t_tab *tab, char *nb)
{
	char	*pad;

	if (nb[0] != '-')
		nb = ft_addsign(nb, tab);
	pad = ft_memset(ft_strnew(tab->width), ' ', tab->width);
	if (!tab->left_align)
		ft_memcpy(&pad[tab->width - (ft_strlen(nb))], nb, ft_strlen(nb));
	else
		ft_memcpy(pad, nb, (ft_strlen(nb)));
	ft_strdel(&nb);
	return (pad);
}
