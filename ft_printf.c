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

const char *g_flags = "+-0 #";
const char *g_identifiers = "cspdiouxXf%";

static char		*choose_cs(va_list ap, t_tab *tab)
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

static void		ft_setflags(t_tab *tab, const char *csp, size_t len)
{
	tab->flag = 0;
	tab->width = ft_atoi(&csp[ft_strspn(csp, g_identifiers)]);
	tab->precision = ft_strchr(csp, '.') ?\
	ft_atoi(&csp[ft_strcspn(csp, ".") + 1]) : -1;
	tab->plus = ft_strchr(csp, '+') ? 1 : 0;
	tab->hash = ft_strchr(csp, '#') ? 1 : 0;
	tab->left_align = ft_strchr(csp, '-') ? 1 : 0;
	tab->empty = ft_strchr(csp, 32) ? 1 : 0;
	tab->zero = ft_strnchr(csp, '0', ft_strcspn(csp, "0123456789")) ?\
	'0' : ' ';
	tab->csp = csp[len - 1];
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
	if (tab->left_align == 1)
		tab->zero = ' ';
}


static void		*ft_copy_format(t_ptr *ptr)
{
	char *temp;

	temp = ft_strdup(ptr->output);
	free(ptr->output);
	ptr->output = (char*)malloc(sizeof(char) * (ft_strlen(temp) + (ptr->i - ptr->j)));
	ptr->output = ft_strjoin(temp, ft_strndup(&(ptr->format[ptr->j]), (ptr->i - ptr->j)));
	ptr->j = ptr->i;
	ptr->output_len = ft_strlen(ptr->output);
	free(temp);
	return(0);
}

static void		*ft_copy_csp(t_ptr *ptr)
{
	t_tab		*tab;
	char		*arg;
	char		*ret;
	char 		*temp;

	tab = (t_tab*)malloc(sizeof(t_tab));
	arg = ft_strndup(&(ptr->format[ptr->i]), ft_strcspn(&(ptr->format[ptr->i + 1]), g_identifiers) + 2);
	ft_setflags(tab, arg, ft_strlen(arg));
	ret = ft_strdup(choose_cs(ptr->ap, tab));
	temp = ft_strdup(ptr->output);
	free(ptr->output);
	ptr->output = (char*)malloc(sizeof(char) * ft_strlen(temp) + ft_strlen(ret) + 1);
	ptr->output = ft_strjoin(temp, ret);
	ptr->j = ptr->i += ft_strlen(arg);
	ptr->output_len += ft_strlen(ret);
	free(temp);
	free(arg);
	free(tab);
	free(ret);
	return(0);
}

void				ft_parse_format(t_ptr *ptr)
{

	while (ptr->format[ptr->i])
	{
		
		while (ptr->format[ptr->i] != '%' && ptr->format[ptr->i])
			ptr->i++;
		if (ptr->format[ptr->i] == '%')
		{
			if (ptr->j != ptr->i)
				ft_copy_format(ptr);
			ft_copy_csp(ptr);
		}
		else
			ft_copy_format(ptr);
	}
	write(1, ptr->output, ptr->output_len);
}

void				ft_init(t_ptr *ptr)
{
	ptr->output = (char*)malloc(sizeof(char));
	ptr->i = 0;
	ptr->j = 0;
	ptr->output_len = 0;
	ptr->add_len = 0;
}

int					ft_printf(const char *format, ...)
{
	t_ptr 		*ptr;
	int			i;

	ptr = (t_ptr*)malloc(sizeof(t_ptr));
	va_start(ptr->ap, format);
	ptr->format = (char*)format;
	ft_init(ptr);
	if (format)
		ft_parse_format(ptr);
	va_end(ptr->ap);
	i = ptr->output_len;
	free(ptr);
	return (i);
}