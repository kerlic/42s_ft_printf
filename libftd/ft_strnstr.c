/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 00:23:04 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/01 16:21:29 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t n;
	size_t l_len;

	l_len = 0;
	while (little[l_len++])
		;
	if (--l_len == 0)
		return ((char *)big);
	while (*big && len)
	{
		n = len--;
		if (*big == *little)
		{
			i = -1;
			while (little[++i] && n--)
				if (big[i] != little[i])
					break ;
			if (i == l_len)
				return ((char *)big);
		}
		big++;
	}
	return (0);
}
