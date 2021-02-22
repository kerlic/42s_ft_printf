/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 02:00:44 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/06 02:33:02 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*ptr;
	size_t	slen;

	slen = ft_strlen(s);
	if (s == 0)
		return (0);
	if (slen < start)
		return (ft_strdup(""));
	if (slen < len)
		len = slen;
	if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ptr = substr;
	while (len-- && s[start])
		*substr++ = s[start++];
	*substr = 0;
	return (ptr);
}
