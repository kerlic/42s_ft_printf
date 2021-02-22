/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 20:02:01 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/06 17:23:04 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	int	n;
	long	int num;

	n = 1;
	while (*str && ((9 <= *str && *str <= 13) || *str == 32))
		str++;
	if (*str == '+' || *str == '-')
		n = (*str++ == '-') ? -1 : 1;
	num = 0;
	while (*str && ('0' <= *str && *str <= '9'))
	{
		num *= 10;
		num = num + *str - '0';
		str++;
		if (num > 2147483647 && n == 1)
			return (-1);
		if (num > 2147483648 && n == -1)
			return (0);
	}
	return (n * num);
}
