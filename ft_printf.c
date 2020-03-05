/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:08:16 by thalme            #+#    #+#             */
/*   Updated: 2019/12/16 15:34:15 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		choose_cs(va_list ap, t_tab *tab)
{
	if (tab->csp == 'c' || tab->csp == '%')
		return (print_char(ap, tab));
	else if (tab->csp == 's' || tab->csp == 'p')
		return (print_string(ap, tab));
	else if (tab->csp == 'f')
		return (print_float(ap, tab, 0));
	else
		return (print_base(ap, tab));
	return (0);
}

static void		ft_setflags(t_tab **tab, const char *csp, size_t len)
{
	(*tab)->flag = 0;
	len = ft_strlen(csp);
	(*tab)->width = ft_atoi(&csp[ft_strspn(csp, "+-0 #")]);
	(*tab)->precision = ft_strchr(csp, '.') ?\
	ft_atoi(&csp[ft_strcspn(csp, ".") + 1]) : -1;
	(*tab)->plus = ft_strchr(csp, '+') ? 1 : 0;
	(*tab)->hash = ft_strchr(csp, '#') ? 1 : 0;
	(*tab)->left_align = ft_strchr(csp, '-') ? 1 : 0;
	(*tab)->empty = ft_strchr(csp, 32) ? 1 : 0;
	(*tab)->zero = ft_strnchr(csp, '0', ft_strcspn(csp, "0123456789")) ?\
	'0' : ' ';
	(*tab)->csp = csp[len - 1];
	if (csp[len - 2] == 'h' && csp[len - 3] == 'h')
		(*tab)->flag = 1;
	else if (csp[len - 2] == 'h' && csp[len - 3] != 'h')
		(*tab)->flag = 2;
	else if (csp[len - 2] == 'l' && csp[len - 3] == 'l')
		(*tab)->flag = 3;
	else if (csp[len - 2] == 'l' && csp[len - 3] != 'l')
		(*tab)->flag = 4;
	else if (csp[len - 2] == 'L')
		(*tab)->flag = 5;
	if ((*tab)->left_align == 1)
		(*tab)->zero = ' ';
}

static int		ft_parseflags(const char *format, va_list ap)
{
	t_tab		*tab;
	char		*arg;
	int			i;
	size_t		len;

	len = 0;
	tab = (t_tab*)malloc(sizeof(t_tab));
	arg = ft_strndup(format, ft_strcspn(format, "cspdiouxXf%") + 1);
	ft_setflags(&tab, arg, len);
	i = choose_cs(ap, tab);
	free(arg);
	free(tab);
	return (i);
}

static int		ft_checkcsp(const char *s, char *charset)
{
	size_t i;
	size_t j;

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (charset[++j])
			if (s[i] == charset[j])
				return (1);
	}
	return (0);
}

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	size_t			charcount;

	charcount = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			charcount++;
		}
		else
		{
			format++;
			if (!(ft_checkcsp(format, "cspdiouxXf%")))
				return (0);
			charcount += ft_parseflags(&(*format), ap);
			format += ft_strcspn(&(*format), "cspdiouxXf%");
		}
		format++;
	}
	va_end(ap);
	return (charcount);
}
