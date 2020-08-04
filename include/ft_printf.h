/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:10:03 by thalme            #+#    #+#             */
/*   Updated: 2019/12/16 16:23:33 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include "../libft/libft.h"

# include <stdio.h>

# define MAX_INT (2147483647)
# define MIN_INT (-MAX_INT - 1)
# define MAX_UINT ((unsigned int)-1)
# define MAX_ULONG ((unsigned long)-1)
# define MAX_ULLONG ((unsigned long long)-1)

/*
** flag [1=hh/char] [2=h/short] [3=ll/long long] [4=l/long] [5=L/long double]
*/

typedef struct		s_ptr
{
	const char		*format;
	char			*output;
	va_list			ap;
	size_t			i;
	size_t			j;
	size_t			output_len;
}					t_ptr;

typedef struct		s_tab
{
	char			csp;
	char			padding_type;
	int				precision;
	size_t			width;
	size_t			plus;
	size_t			left_align;
	size_t			empty;
	size_t			hash;
	size_t			flag;
	size_t			roundup;
	size_t			is_null;
	size_t			negative;
}					t_tab;

int					ft_printf(const char *str, ...);
char				*print_char(va_list ap, t_tab *tab);
char				*print_string(va_list ap, t_tab *tab);
char				*print_float(va_list ap, t_tab *tab);
char				*print_base(va_list ap, t_tab *tab);
void				ft_parse_format(t_ptr *ptr);
void				ft_setflags(t_tab *tab, const char *csp,\
					size_t len, t_ptr *ptr);

char				*ft_zeropadding(t_tab *tab, char *number);
char				*ft_emptypadding(t_tab *tab, char *number);
char				*ft_addsign(char *str, t_tab *tab);
char				*ft_choosepadding(t_tab *tab, char *number);
char				*ft_handle_precision(t_tab *tab, char *nb);
char				*ft_superjoin(int count, ...);

long long			ft_select_type_signed(va_list ap, t_tab *tab);
unsigned long long	ft_select_type_unsigned(va_list ap, t_tab *tab);

#endif
