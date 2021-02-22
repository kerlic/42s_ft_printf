/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 01:49:04 by ilsong            #+#    #+#             */
/*   Updated: 2020/12/29 04:02:14 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*ptr;
	size_t	len;
	size_t	idx;

	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	ptr = str;
	if (str == 0)
		return (0);
	idx = 0;
	while (*s && idx < len)
		*str++ = f(idx++, *s++);
	*str = 0;
	return (ptr);
}
