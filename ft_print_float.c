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

#include "ft_printf.h"

static int		ft_round(char *nb)
{
	size_t		len;
	int			i;

	len = ft_strlen(nb);
	if (nb[len - 1] > '5')
	{
		nb[len - 2] += 1;
		while (nb[len - 2] == ':')
		{
			len--;
			nb[len - 2] += 1;
		}
	}
	i = -1;
	while (nb[++i])
		if (nb[i] == ':')
			nb[i] = '0';
	nb[ft_strlen(nb) - 1] = '\0';
	len--;
	return (len);
}

static char		*ft_decimal(double nb, t_tab *tab, size_t negative)
{
	char		*decimal;
	int			count;
	int			integer;

	(tab)->roundup = 0;
	decimal = ft_strnew(tab->precision);
	if (nb < 0)
		nb = nb * -1;
	count = 0;
	while (count <= tab->precision)
	{
		integer = nb *= 10;
		decimal[count++] = integer + 48;
		nb -= integer;
	}
	if (tab->precision == 0 && decimal[0] > '5' && negative != 1)
		tab->roundup = 1;
	decimal[count] = '\0';
	return (decimal);
}

static char		*ft_float_hash(t_tab *tab, char *nb)
{
	if (tab->hash == 1)
		nb = ft_superjoin(2, nb, ".");
	return (nb);
}

char				*print_float(va_list ap, t_tab *tab, size_t negative)
{
	long		integer;
	long double	double_nb;
	char		*nb;

	tab->precision += tab->precision == -1 ? 7 : 0;
	if (tab->flag == 5)
		double_nb = va_arg(ap, long double);
	else
		double_nb = va_arg(ap, double);
	negative = double_nb < 0 ? 1 : 0;
	double_nb *= double_nb > 0 ? 1 : -1;
	integer = double_nb;
	nb = ft_decimal((double_nb - (double)integer), tab, negative);
	if (ft_round(nb) == 0 && nb[0] == '0')
		integer++;
	integer += tab->roundup;
	if (nb[0] != '\0' && tab->precision != 0)
		nb = ft_superjoin(3, ft_itoa_base(integer, 10), ".", nb);
	else
		nb = ft_float_hash(tab, ft_itoa_base(integer, 10));
	nb = ft_choosepadding(tab, nb, negative);
	return (nb);
}
