/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:37:06 by thalme            #+#    #+#             */
/*   Updated: 2020/03/05 15:37:27 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define FD 2048
# define BUFF_SIZE 10

int			get_next_line(const int fd, char **line);

#endif
