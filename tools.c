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

#include "ft_printf.h"

char		*ft_handle_precision(t_tab *tab, char *nb)
{
	char	*pad;

	pad = ft_memset(ft_strnew(tab->precision), '0', tab->precision);
	ft_memcpy(&pad[tab->precision - (ft_strlen(nb))], nb, ft_strlen(nb));
	free(nb);
	return (pad);
}

char		*ft_choosepadding(t_tab *tab, char *nb, size_t neg)
{
	if (ft_strlen(nb) < tab->width)
	{
		if (tab->zero == '0')
			nb = ft_zeropadding(tab, nb, neg);
		else
			nb = ft_emptypadding(tab, nb, neg);
	}
	else
		nb = ft_addpme(nb, tab, neg);
	return (nb);
}

char		*ft_emptypadding(t_tab *tab, char *nb, size_t neg)
{
	char	*pad;

	if (nb[0] != '-')
		nb = ft_addpme(nb, tab, neg);
	pad = ft_memset(ft_strnew(tab->width), ' ', tab->width);
	if (tab->left_align == 0)
		ft_memcpy(&pad[tab->width - (ft_strlen(nb))], nb, ft_strlen(nb));
	else
		ft_memcpy(pad, nb, (ft_strlen(nb)));
	free(nb);
	return (pad);
}

char		*ft_zeropadding(t_tab *tab, char *nb, size_t neg)
{
	char	*pad;
	size_t	padlen;

	padlen = 0;
	tab->empty *= tab->plus == 1 ? 0 : 1;
	tab->plus *= neg == 1 ? 0 : 1;
	padlen = tab->width - tab->plus - tab->empty - neg - tab->hash;
	pad = ft_memset(ft_strnew(padlen), '0', padlen);
	if (tab->left_align == 0)
		ft_memcpy(&pad[padlen - (ft_strlen(nb))], nb, ft_strlen(nb));
	else
		ft_memcpy(pad, nb, (ft_strlen(nb)));
	pad = ft_addpme(pad, tab, neg);
	free(nb);
	return (pad);
}
