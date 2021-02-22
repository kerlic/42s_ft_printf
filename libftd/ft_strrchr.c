/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 00:13:14 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/05 21:58:03 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int n;

	n = 0;
	while (*str++)
		n++;
	while (n-- >= 0)
		if (*(--str) == (char)ch)
			return ((char *)str);
	return (0);
}
