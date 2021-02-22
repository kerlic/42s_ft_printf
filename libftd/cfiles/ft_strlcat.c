/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:53:09 by ilsong            #+#    #+#             */
/*   Updated: 2020/12/29 18:21:27 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size < dest_len + 1)
		return (size + src_len);
	else if (size > dest_len + 1)
	{
		while (src[i] && dest_len + 1 + i < size)
		{
			dst[dest_len + i] = src[i];
			i++;
		}
	}
	dst[dest_len + i] = 0;
	return (dest_len + src_len);
}
