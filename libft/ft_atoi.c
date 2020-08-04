/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:17:58 by thalme            #+#    #+#             */
/*   Updated: 2019/10/24 15:28:01 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int count;
	int neg;
	int ret;
	int i;

	i = 0;
	neg = 1;
	count = 0;
	while ((str[count] >= 7 && str[count] <= 13) || str[count] == 32)
		count++;
	if (str[count] == '-')
	{
		neg = neg * -1;
		count++;
	}
	if (str[count] == '+' && neg == 1)
		count++;
	while (str[count] >= 48 && str[count] <= 57)
	{
		ret = str[count] - 48;
		i = (i * 10) + ret;
		count++;
	}
	return (i * neg);
}
