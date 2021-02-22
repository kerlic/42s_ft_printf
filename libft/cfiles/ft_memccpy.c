/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:17:05 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/06 19:54:36 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t count)
{
	unsigned	char	*tmp;
	unsigned	char	*s_tmp;

	tmp = dest;
	s_tmp = (unsigned char *)src;
	while (count--)
	{
		*tmp++ = *s_tmp++;
		if (*(s_tmp - 1) == (unsigned char)c)
			return (tmp);
	}
	return (0);
}
