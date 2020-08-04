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

#include "../include/ft_printf.h"

void				ft_init(t_ptr *ptr)
{
	ptr->output = (char*)malloc(sizeof(char*));
	ptr->i = 0;
	ptr->j = 0;
	ptr->output_len = 0;
}

int					ft_printf(const char *format, ...)
{
	t_ptr		*ptr;
	int			i;

	i = 0;
	if (format)
	{
		ptr = (t_ptr*)malloc(sizeof(t_ptr));
		va_start(ptr->ap, format);
		ptr->format = format;
		ft_init(ptr);
		ft_parse_format(ptr);
		va_end(ptr->ap);
		i = ptr->output_len;
		ft_strdel(&ptr->output);
		free(ptr);
	}
	return (i);
}
