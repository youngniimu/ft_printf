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
# include "libft.h"

/*
** flag [1=hh/char] [2=h/short] [3=ll/long long] [4=l/long] [5=L/long double]
*/

typedef struct		s_tab
{
	int				precision;
	size_t			width;
	size_t			plus;
	size_t			left_align;
	size_t			empty;
	size_t			hash;
	char			zero;
	size_t			flag;
	char			csp;
	int				roundup;
}					t_tab;

int					ft_printf(const char *str, ...);
int					print_char(va_list ap, t_tab *tab);
int					print_string(va_list ap, t_tab *tab);
int					print_float(va_list ap, t_tab *tab, size_t negative);
int					print_base(va_list ap, t_tab *tab);

char				*ft_zeropadding(t_tab *tab, char *number, size_t neg);
char				*ft_emptypadding(t_tab *tab, char *number, size_t neg);
char				*ft_addpme(char *str, t_tab *tab, size_t negative);
char				*ft_choosepadding(t_tab *tab, char *number, size_t neg);
char				*ft_handle_precision(t_tab *tab, char *nb);
char				*ft_superjoin(int count, ...);

long long			ft_select_type_signed(va_list ap, t_tab *tab);
unsigned long long	ft_select_type_unsigned(va_list ap, t_tab *tab);

#endif
