/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:08:16 by thalme            #+#    #+#             */
/*   Updated: 2020/07/29 17:08:37 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_vswap(void *a, void *b, size_t width)
{
	void	*temp;

	temp = malloc(width);
	ft_memcpy(temp, b, width);
	ft_memcpy(b, a, width);
	ft_memcpy(a, temp, width);
	free(temp);
}
