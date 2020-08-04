/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:15:52 by thalme            #+#    #+#             */
/*   Updated: 2020/07/29 17:15:54 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char		*choose_cs(va_list ap, t_tab *tab)
{
	if (tab->csp == 'c' || tab->csp == '%')
		return (print_char(ap, tab));
	else if (tab->csp == 's' || tab->csp == 'p')
		return (print_string(ap, tab));
	else if (tab->csp == 'f')
		return (print_float(ap, tab));
	else
		return (print_base(ap, tab));
	return (0);
}

static void		ft_copy_csp(t_ptr *ptr)
{
	t_tab		*tab;
	char		*csp;
	char		*ret;
	char		*temp;

	tab = (t_tab*)malloc(sizeof(t_tab));
	csp = ft_strndup(&(ptr->format[ptr->i]), \
	ft_strcspn(&(ptr->format[ptr->i + 1]), "cspdiouxXf%") + 2);
	ft_setflags(tab, csp, ft_strlen(csp), ptr);
	temp = ft_strdup(ptr->output);
	ft_strdel(&ptr->output);
	ret = choose_cs(ptr->ap, tab);
	ptr->output = ft_strjoin(temp, ret);
	ptr->j = ptr->i += ft_strlen(csp);
	ptr->output_len += tab->width >= ft_strlen(ret)
	? tab->width
	: ft_strlen(ret);
	ptr->output_len += tab->is_null;
	ft_strdel(&ret);
	ft_strdel(&temp);
	ft_strdel(&csp);
	free(tab);
}

static void		ft_copy_format(t_ptr *ptr)
{
	char		*temp;
	char		*temp2;

	temp = ft_strdup(ptr->output);
	ft_strdel(&ptr->output);
	temp2 = ft_strndup(&(ptr->format[ptr->j]), (ptr->i - ptr->j));
	ptr->output = ft_strjoin(temp, temp2);
	ptr->output_len += (ptr->i - ptr->j);
	ptr->j = ptr->i;
	ft_strdel(&temp);
	ft_strdel(&temp2);
}

void			ft_parse_format(t_ptr *ptr)
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
