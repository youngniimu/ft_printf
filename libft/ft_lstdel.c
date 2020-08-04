/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:01:24 by thalme            #+#    #+#             */
/*   Updated: 2019/10/29 13:32:09 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *node;

	node = *alst;
	while (node->next)
	{
		del(node->content, node->content_size);
		node = node->next;
	}
	del(node->content, node->content_size);
	free(node);
	node = NULL;
	free(*alst);
	*alst = NULL;
}
