/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 23:39:12 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/06 00:35:52 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	if (!dest && !src)
		return (0);
	ptr_dest = dest;
	ptr_src = (unsigned char *)src;
	i = 0;
	while (i++ < num)
		*ptr_dest++ = *ptr_src++;
	return (dest);
}
